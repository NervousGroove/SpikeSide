std::ifstream file("spikeconfig.spike");
std::string fileDir;
if (file.is_open()) {
    std::getline(file, fileDir);
    file.close();
}


std::ifstream file(fileDir);
std::string line;
if (file.is_open()) {
    while (std::getline(file, line)) {
        if (line.find("vlu(") != std::string::npos) {
            std::string name = line.substr(line.find_first_of("\"") + 1, line.find_last_of("\"") - line.find_first_of("\"") - 1);
            std::string value = line.substr(line.find_last_of("\"") + 2, line.find_last_of(")") - line.find_last_of("\"") - 3);
            std::string newVar = "std::string " + name + " = \"" + value + "\";\n";
            std::cout << newVar;
        }
    }
    file.close();
}


