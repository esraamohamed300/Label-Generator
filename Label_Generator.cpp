
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <limits> 
using namespace std;

class LabelCreator {
protected:
    string labelPrefix;
    int labelIndex;

public:
    LabelCreator(const string& prefix, int startIndex = 1) : labelPrefix(prefix), labelIndex(startIndex) {}

    virtual string generateLabel() {
        return labelPrefix + " " + to_string(labelIndex++) + ".";
    }
};

class FileLabelCreator : public LabelCreator {
private:
    string captionsFileName;
    vector<string> captionsList;
    int captionsIndex;

    void loadCaptionsFromFile() {
        ifstream fileStream(captionsFileName);
        while (!fileStream.is_open()) {
            cerr << "Error: Could not open file " << captionsFileName << endl;
            cout << "Error: Enter a valid filename please: ";
            getline(cin, captionsFileName);
            fileStream.open(captionsFileName);
        }

        string line;
        captionsList.clear();
        while (getline(fileStream, line)) {
            captionsList.push_back(line);
        }
        fileStream.close();
        captionsIndex = 0;
    }

public:
    FileLabelCreator(const string& prefix, int startIndex, const string& fileName)
        : LabelCreator(prefix, startIndex), captionsFileName(fileName), captionsIndex(0) {
        loadCaptionsFromFile();
    }

    string generateLabel() override {
        string label = LabelCreator::generateLabel();
        if (captionsIndex < captionsList.size()) {
            label += " " + captionsList[captionsIndex++];
        }
        return label;
    }

    void resetLabels() {
        labelIndex = 1;
        captionsIndex = 0;
    }

    size_t getCaptionsCount() const {
        return captionsList.size();
    }
};

int main() {
    string userLabelPrefix;
    int startingLabelIndex;
    string captionsFile;

    
    cout << "Enter the label prefix like ('Figure', 'Table', 'Chart','Diagram') or any label you like : ";
    getline(cin, userLabelPrefix);

    while (true) {
        cout << "Enter the starting number or it will be '1' by default: ";
        cin >> startingLabelIndex;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Error: Enter a valid number please." << endl;
        }
        else {
            cin.ignore();
            break;
        }
    }

    
    cout << "Enter the filename with its extention: ";
    getline(cin, captionsFile);

    FileLabelCreator labelCreator(userLabelPrefix, startingLabelIndex, captionsFile);
    cout << "Here is your Generated labels: " << endl;
    for (size_t i = 0; i < labelCreator.getCaptionsCount(); i++) {
        cout << labelCreator.generateLabel() << endl;
    }

    return 0;
}
