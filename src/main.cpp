#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/variables_map.hpp>
#include <iostream>
#include <boost/program_options.hpp>
#include "config.h"
#include "config.h.in"
#include <string>

namespace po = boost::program_options;

void PrintVersion()
{
    std::cout << PROJECT_NAME << 
        ' ' << PROJECT_VERSION << '\n';
}

void PrintHelp(po::options_description desc)
{
    std::cout << PROJECT_NAME << ". " << PROJECT_DESCRIPTION << '\n';
    std::cout << desc << '\n';
}

int ProcessArgs(int argc, char *argv[]){
    po::options_description desc("Generic options");
    desc.add_options()
        ("help,h", "show this message")
        ("version", "show current version")
    ;
    po::variables_map vm;
    try{
            po::store(po::parse_command_line(argc, argv, desc), vm);
    } catch (boost::wrapexcept<boost::program_options::unknown_option> e){
        std::cout << e.what() << '\n';
        return 1;
    }
    po::notify(vm);

    if (vm.count("help"))
    {
        PrintHelp(desc);
        return 1;
    }
    if (vm.count("version"))
    {
        PrintVersion();
        return 1;
    }

    return 0;
}

int main(int argc, char *argv[]){
    int exitCode = ProcessArgs(argc, argv);
    if (exitCode != 0)
        return exitCode;

    return 0;
}
