#!/bin/bash

dot_dir="./dot_files"
for file in "$dot_dir"/*.dot; do
    filename=$(basename "$file")
    pdf_file="./pdfs/${filename%.dot}.pdf"
    dot -Tpdf "$file" > "$pdf_file"
done
