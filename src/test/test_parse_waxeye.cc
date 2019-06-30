#include "parse/waxeye.hh"

#include <exception>
#include <fstream>
#include <iostream>
#include <string>

int
main
(
    int    argc,
    char * argv [ ] 
)
{
    ( void ) argc;
    ( void ) argv;
    int result = 0;
    try
    {
        const char * grammar_file_name = "../../../grammar/waxeye.waxeye" ;
        std::ifstream f;
        f . open ( grammar_file_name ) ;
        if ( f . is_open ( ) )
        {
            std::string s ( std::istreambuf_iterator < char > ( f ), { } ) ;
            f . close ( ) ;
            xp::parse::waxeye waxeye;
            std::cout << waxeye . parse ( s ) << std::endl ;
        }
        else
        {
            std::cerr << "Could not open " << grammar_file_name << std::endl ;
            result = 1;
        }
    }
    catch ( const std::exception e )
    {
        std::cerr << e.what ( ) << std::endl;
        result = -1;
    }
    return result;
}
