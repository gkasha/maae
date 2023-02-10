from setuptools import find_packages
from setuptools import setup

setup(
    name='ma_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('ma_interfaces', 'ma_interfaces.*')),
)
