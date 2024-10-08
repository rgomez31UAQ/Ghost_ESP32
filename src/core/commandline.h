#pragma once

#include <core/system_manager.h>
#include <LinkedList.h>
#include <ArduinoJson.h>

class CommandLine {
  public:
    static CommandLine& getInstance() {
        static CommandLine instance;
        return instance;
    }
    String getSerialInput();
    LinkedList<String> parseCommand(String input, char* delim);
    String toLowerCase(String str);
    void runCommand(String input);
    bool checkValueExists(LinkedList<String>* cmd_args_list, int index);
    bool inRange(int max, int index);
    bool hasSSIDs();
    int argSearch(LinkedList<String>* cmd_args, String key);
public:
    CommandLine();

    void RunSetup();
    void main(uint32_t currentTime);
    uint8_t count_selected;
};