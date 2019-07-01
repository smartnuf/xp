#include "waxeye.hh"

#include <iostream>

namespace xp
{
    namespace parse
    {
        //
        // Data members
        //

        //
        // Member furnctions
        //

        // public
        //

        bool
        waxeye::
        parse 
        ( 
            const std::string & text
        )
        {
            m_text = text;
            m_text_pos = m_text . cbegin ( );
            return match_grammar ( );
        }
        
        //
        // private
        //

        // grammar <- ws * definition
        bool 
        waxeye :: 
        match_grammar ( )
        {
            if ( match_ws ( ) )
            {
                if ( match_definition ( ) )
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                std::cerr << "expected ws at pos 0" << std::endl;
                return false;
            }
        }

        bool 
        waxeye ::
        match_definition ( ) 
        {
            return false;
        }

        bool 
        waxeye :: 
        match_alternation ( )
        {
            return false;
        }

        bool 
        waxeye :: 
        match_sequence ( )
        {
            return false;
        }

        bool 
        waxeye :: 
        match_unit ( )
        {
            return false;
        }

        bool 
        waxeye ::
        match_prefix ( )
        {
            return false;
        }

        bool 
        waxeye ::
        match_label ( )
        {
            return false;
        }

        bool 
        waxeye ::
        match_action ( )
        {
            return false;
        }
        
        bool 
        waxeye ::
        match_identifier ( )
        {
            return false;
        }
        
        bool
        waxeye ::
        match_literal ( )
        {
            return false;
        }
        
        bool 
        waxeye ::
        match_i_case_leteral ( )
        {
            return false;
        }
        
        bool 
        waxeye ::
        match_char_class ( )
        {
            return false;
        }
        
        bool 
        waxeye ::
        match_char_range ( )
        {
            return false;
        }
        
        bool 
        waxeye ::
        match_char ( )
        {
            return false;
        }

        bool 
        waxeye :: 
        match_hex_char ( )
        {
            return false;
        }
        
        bool waxeye :: 
        match_wild_card ( )
        {
            return false;
        }
        
        bool 
        waxeye ::
        match_left_arrow ( )
        {
            return false;
        }
        
        bool 
        waxeye ::
        match_prune_arrow ( )
        {
            return false;
        }
        
        bool 
        waxeye ::
        match_void_arrow ( )
        {
            return false;
        }
        
        bool 
        waxeye ::
        match_alt ( )
        {
            return false;
        }
        
        bool 
        waxeye ::
        match_open ( )
        {
            return false;
        }
        
        bool 
        waxeye ::
        match_close ( )
        {
            return false;
        }
        
        bool 
        waxeye ::
        match_comma ( )
        {
            return false;
        }
        
        bool 
        waxeye ::
        match_eol_comment ( )
        {
            return false;
        }
        
        bool waxeye ::
        match_mul_comment ( )
        {
            return false;
        }
        
        bool
        waxeye ::
        match_eol ( )
        {
            return 
            (
                match_string ( "\r\n" ) ||
                match_string ( "\n" ) ||
                match_string ( "\r" )
            );
        }
        
        bool
        waxeye ::
        match_ws ( )
        {
            std::string::const_iterator text_pos = m_text_pos;
            while 
            (
                match_char_class ( " \t" ) ||
                match_eol ( )              ||
                match_eol_comment ( )      ||
                match_mul_comment ( )
            )
            {
                // contiue
            }
        }

        // <- [ ]
        bool 
        waxeye ::
        match_char_class 
        ( 
            const char * char_class 
        )
        {
            bool result = true;
            if ( * char_class != '\0' )
            {
                result = false;
                if ( m_text_pos != m_text.end ( ) )
                {
                    for ( int i = 0; char_class [ i ] != 0; i++ )
                    {
                        if ( * m_text_pos == char_class [ i ] )
                        {
                            result = true;
                            ++ m_text_pos;
                            break;
                        }
                    }
                }                
            }
            return result;
        }

        // <- ' '
        bool 
        waxeye ::
        match_string 
        ( 
            const char * str 
        )
        {
            bool result = true;
            std::string::const_iterator pos = m_text_pos;
            for ( int i = 0; str [ i ] != '\0'; ++ i, ++ pos )
            {
                if
                ( 
                    pos == m_text . cend ( ) ||
                    * pos != str [ i ]
                )
                {
                    result = false;
                    break;
                }
            }
            if ( result )
            {
                m_text_pos = pos;
            }
            return result;
        }
    }
}
