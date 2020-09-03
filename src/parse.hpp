#include "symbol_table.hpp"
#include <vector>
#include <bits/stdc++.h>
#include <cstring>
#include <unordered_map>
#include <bitset>
#include <fstream>

class Parse
{
public:
    std::vector<std::string> instructions; //string vector to store all instructions
    std::ifstream file;                    //standard input filestream
    SymbolTable table;
    std::string filepath;

    Parse(std::string filepath)
    {
        /*  
        parameterised constructor. opens th file and stores each instruction
        in a vector after removing all the spaces and comments
        */
        filepath = filepath;
        try
        {
            file.open(filepath);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        if (file.is_open())
        {
            std::string temp;
            while (std::getline(file, temp))
            {
                if (temp.front() == '/') //comments
                    continue;
                temp.erase(0, temp.find_first_not_of(" \r\t\v\n"));                 //head-spaces
                temp.erase(std::min(temp.find_first_of(" \r\t\v\n"), temp.size())); //traling spaces
                instructions.push_back(temp);
            }
            file.close();
        }
    }

    char get_instruction_type(std::string inst)
    {
        //get the type of instruction being processed
        if (inst.front() == '(' && inst.back() == ')')
        {
            return 'L'; //labels
        }
        else if (inst.front() == '@')
        {
            return 'A'; //A instructions
        }
        else
        {
            return 'C'; //C instructions
        }
    }

    std::vector<std::string> add_symbols()
    {
        std::vector<std::string> first_pass;
        first_pass.reserve(instructions.size());
        int inst_count = -1; //set the actual line of instruction to handle labels properly

        for (std::string inst : instructions)
        {
            inst_count++;
            if (get_instruction_type(inst) == 'L')
            {
                inst.erase(0, 1);
                inst.erase(inst.size() - 1);
                table.insert_symbol(inst, inst_count);
                continue;
            }
            first_pass.push_back(inst);
        }

        return first_pass;
    }

    bool isNumber(std::string str)
    {
        //check if a string contains only numbers
        return (!str.empty() && std::all_of(str.begin(), str.end(), ::isdigit));
    }

    void assemble(std::vector<std::string> firstpass)
    {
        // just like 'Cap asked
        int pos = filepath.find_last_of('\\');
        int pos_dot = filepath.find('.');
        std::string outfile_name = filepath.substr(pos + 1).erase(pos_dot);
        outfile_name = outfile_name + ".hack"; //create a correct output filename
        std::ofstream outfile(outfile_name);   //open output filestream

        for(std::string inst : firstpass)
        {
            char type = get_instruction_type(inst);

            switch (type)
            {
            case 'L':
                /* code */
                break;
            case 'A':
                //code
                break;
            case 'C':
                //code
                break;
            default:
                break;
            }
        }
    }
};