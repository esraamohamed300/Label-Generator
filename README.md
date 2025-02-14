# Label Generator Project 🎯

📌 Project Description

This project is a Label Generator that automates the process of creating labeled captions. It allows users to specify a prefix (e.g., "Figure", "Table", "Chart"), set a starting number, and read captions from a file to generate structured labels automatically.

✨ Features

✅ Customizable label prefix (e.g., "Figure", "Diagram")

✅ User-defined starting index for numbering

✅ Reads captions from an external text file 📄

✅ Error handling for invalid file input and non-numeric indexes

✅ Reset functionality to restart label generation

🛠 Technologies Used

C++ for implementation

File Handling for reading captions

OOP Principles (Inheritance, Encapsulation, and Polymorphism)

🚀 How to Use

Clone the repository:

git clone https://github.com/yourusername/LabelGenerator.git
cd LabelGenerator

Compile the project:

g++ -o LabelGenerator main.cpp

Run the program:

./LabelGenerator

Follow the on-screen instructions:

Enter a label prefix (e.g., "Figure")

Specify a starting number (default is 1)

Provide a valid filename containing captions

The program will generate labels in the format:

Figure 1. Caption 1
Figure 2. Caption 2
...

📂 Example Input File

Sunset over the mountains
A beautiful river flows
City skyline at night

🔥 Example Output

Figure 1. Sunset over the mountains
Figure 2. A beautiful river flows
Figure 3. City skyline at night

📝 Notes

Ensure the caption file exists and has content.

Enter a valid number for the starting index.

If an invalid file name is entered, the program will prompt for a correct one.

📢 Contributing

Feel free to fork this repo, submit issues, and contribute improvements! 🎉

📜 License

This project is open-source and available under the MIT License.
