#include "Engine.h"
#include "Wrapper.h"
#include "Subject.h"
#include "FileReader.h"  
#include <iostream>

int main() {
    std::string filename = "input.txt";
    std::string fileContent;

    try {
        FileReader fileReader(filename);
        fileContent = fileReader.getFileContent();
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    Subject subj;
    Wrapper wrapper(&subj, [&subj](const std::unordered_map<std::string, std::string>& args) { return subj.f3(args); },
                    {{"operation", ""}, {"text", ""}, {"find", ""}, {"replace_with", ""}});

    Engine engine;
    engine.register_command(&wrapper, "command1");

    std::unordered_map<std::string, std::string> args = {
        {"operation", "number_sentences"}, {"text", fileContent}
    };

    std::string result = engine.execute("command1", args);
    std::cout << "Processed text:\n" << result << std::endl;

    return 0;
}