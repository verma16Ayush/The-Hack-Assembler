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
                if (temp.front() == '/' || temp.empty()) //comments
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

    bool is_number(std::string str)
    {
        //check if a string contains only numbers
        return (!str.empty() && std::all_of(str.begin(), str.end(), ::isdigit));
    }

    void assemble(std::vector<std::string> firstpass, std::string out_filename)
    {
        // just like 'Cap asked
        int pos = out_filename.find_last_of('\\');
        int pos_dot = out_filename.find('.');
        out_filename.erase(pos_dot);
        std::string outfile_name = out_filename.substr(pos+1);
        outfile_name = outfile_name + ".hack"; //create a correct output filename
        std::ofstream outfile(outfile_name);   //open output filestream

        for (std::string inst : firstpass)
        {
            char type = get_instruction_type(inst);

            switch (type)
            {
                case 'L':
                {
                    std::cout << "this shouldn't have happened" << std::endl;
                    break;
                }
                case 'A':
                {
                    std::string rem = inst.substr(1);
                    if (is_number(rem))
                    {
                        std::string bits = std::bitset<15>(std::stoi(rem)).to_string();
                        outfile << "0" << bits << '\n';
                    }
                    else
                    {
                        int mem_loc = table.is_present(rem);
                        if (mem_loc == -1)
                        {
                            mem_loc = table.available_address();
                            table.insert_symbol(rem, mem_loc);
                        }
                        std::string bits = std::bitset<15>(mem_loc).to_string();
                        outfile << "0" << bits << '\n';
                    }
                    break;
                }
                case 'C':
                {
                    int eq_pos = inst.find('=');
                    int semi_pos = inst.find(';');

                    std::string comp_bits, dest_bits, jump_bits;
                    dest_bits = (eq_pos == -1) ? "000" : table.dest[inst.substr(0, eq_pos)];
                    jump_bits = (semi_pos == -1) ? "000" : table.jump[inst.substr(semi_pos+1)];

                    if(eq_pos == -1)
                    {
                        comp_bits = table.comp[inst.substr(0, semi_pos)];
                    }

                    else if (semi_pos == -1)
                    {
                        comp_bits = table.comp[inst.substr(eq_pos+1)];
                    }

                    outfile << "111" << comp_bits << dest_bits << jump_bits << '\n';
                    break;
                }
                default:
                {
                    break;
                }
            }
        }
    }
};