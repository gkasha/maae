#include "auction/execution_interface.hpp"

void Monitor::print_action_counter() {
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "\n=============Action Counter=============\n");
    
    std::string res = "Agent\tMakespan\tTravel Time";
    for (auto const& elt : action_counter) {
        res += "\n" + elt.first + ": " + std::to_string(elt.second[0]) + "\t" + std::to_string(elt.second[1]) + "\t" + std::to_string(elt.second[2]);
    }
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "%s\n======================================", res.c_str());
}

void Monitor::action_dispatch_cb(const ma_interfaces::msg::ActionDispatch action) {
    mtx.lock();
    ActionNode* a_node = new ActionNode(action);
    action_map[a_node->to_string()] = a_node;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(action.duration - action.execution_range, action.duration+action.execution_range);
    double execution_time = distr(gen);
    // if (action.action_id == "task1") execution_time = action.duration - action.execution_range;

    if (action.num_agents <= 1) {
        a_node->set_start_time(curr_time_);
        a_node->set_duration(execution_time);
        a_node->set_status(ActionNode::EXECUTING);
        
        publisher_->publish(a_node->to_feedback_msg(curr_time_));
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "\n\t[%d] Action started: %s\n\t\test duration=%f\trange=%f\tactual=%f", curr_time_, a_node->to_string().c_str(), action.duration, action.execution_range, execution_time);
    } else {
        if (joint_map.find(action.action_id) != joint_map.end()) {
            joint_map[action.action_id].push_back(a_node);
            int curr_agents = joint_map[action.action_id].size();
            if (curr_agents == action.num_agents) {
                RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "\n\t[%d] Action %s has sufficient agents: %d", curr_time_, action.action_id.c_str(), curr_agents);
                for (ActionNode* node : joint_map[action.action_id]) {
                    node->set_start_time(curr_time_);
                    node->set_duration(execution_time);
                    node->set_status(ActionNode::EXECUTING);

                    publisher_->publish(node->to_feedback_msg(curr_time_));
                    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "\n\t[%d] Action started: %s\n\t\test duration=%f\trange=%f\tactual=%f", curr_time_, node->to_string().c_str(), node->get_duration(), action.execution_range, execution_time);
                }
                joint_map.erase(action.action_id);
            }
        } else {
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "\n\t[%d] Action received, first of two: %s", curr_time_, action.action_id.c_str());
            joint_map[action.action_id] = std::vector<ActionNode*>{a_node};
        }
    }
    mtx.unlock();
}

void Monitor::action_modification_cb(const ma_interfaces::msg::ActionFeedback action) {
    std::string key = action.action_id + "_" + action.agent_id + "_" + action.name;

    if (action_map.find(key) != action_map.end()) {
        if (action.action_failed) {
            action_map[key]->set_status(ActionNode::FAILED);
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"),"Failing action %s", action_map[key]->to_string().c_str());
        } else {
            action_map[key]->set_duration(action_map[key]->get_duration() + action.time);
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"),"Delaying action %s by %f", action_map[key]->to_string().c_str(), action.time);
        }
    } else {
        for (auto const& elt : action_map) {
            if (elt.second->get_action_id() == action.action_id) {
                if (action.action_failed) {
                    elt.second->set_status(ActionNode::FAILED);
                    RCLCPP_INFO(rclcpp::get_logger("rclcpp"),"Failing action %s", elt.second->to_string().c_str());
                } else {
                    elt.second->set_duration(elt.second->get_duration() + action.time);
                    RCLCPP_INFO(rclcpp::get_logger("rclcpp"),"Delaying action %s by %f", elt.second->to_string().c_str(), action.time);
                }
            }
        }
    }
}

int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);

    rclcpp::executors::MultiThreadedExecutor executor;
    auto monitor_node = std::make_shared<Monitor>();

    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Execution interface started");

    executor.add_node(monitor_node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}
