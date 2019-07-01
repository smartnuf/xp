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
            bool result = false;
            if ( match_ws ( ) )
            {
                if ( match_definition ( ) )
                {
                    result = true;
                }
                else
                {
                    std::cerr << "expected definition" << std::endl;
                    result = false;
                }
            }
            else
            {
                // Sould never happen
                // perhaps we should call it opt_ws, and return false
                // if is the empty string?
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
        
        // <: '#' * ( ! EndOfLine . ) ( EndOfLine | !. )
        bool 
        waxeye ::
        match_eol_comment ( )
        {
            bool result = false;
            if ( match_string ( "#" ) )
            {
                result = true;
                while 
                (
                    not_eol ( ) && match_any_char ( ) 
                )
                {
                    // Continue    
                }
                // note how the expression value is un important here
                // only the side effect of match_eol ( ) actuall matters
                ( void ) ( match_eol ( ) || is_eof ( ) );
            }
            else
            {
                result = false;
            }
            return result;
        }
        
        // <: '/*' * ( MComment | ! '*/' . ) '*/'
        bool waxeye ::
        match_mul_comment ( )
        {
            bool result = false;
            const std::string::const_iterator pos_on_entry = m_text_pos;
            if ( match_string ( "/*" ) )
            {
                while 
                (
                    match_mul_comment ( )  ||
                    not_string ( "*/" )    && 
                    match_any_char ( )
                )
                {
                    // Continue
                }
                if ( match_string ( "*/" ) )
                {
                    result = true;
                }
                else
                {
                    m_text_pos = pos_on_entry;
                    result = false;
                }
            }
            
            return result;
        }
        
        // <: '\r\n' 
        //   | '\n' 
        //   | '\r'
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

        // <: * ( [ \t] | eol | eol_comment | mul_comment )        
        bool
        waxeye ::
        match_ws ( )
        {
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
            return true;
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

        // .
        bool
        waxeye ::
        match_any_char ( )
        {
            bool result = false;
            if ( m_text_pos == m_text . cend ( ) )
            {
                result = false;
            }
            else
            {
                result = true;
                ++ m_text_pos;
            }
        }

        // ! .
        bool
        waxeye :: 
        not_any_char ( )
        {
            return m_text_pos == m_text . cend ( );
        }

        // ! .
        bool
        waxeye ::
        is_eof ( )
        {
            return m_text_pos == m_text . cend ( );
        }

        // ! ' '
        bool 
        waxeye ::
        not_string 
        ( 
            const char * cstr 
        )
        {
            bool result = false;
            std::string::const_iterator pos = m_text_pos;
            for ( int i = 0; cstr [ i ] != '\0'; ++ i, ++ pos )
            {
                if 
                ( 
                    pos == m_text . cend ( ) ||
                    * pos != cstr [ i ] )
                {
                    result = true;
                    break;
                }
            }
            return result;
        }

        // ! ( "\r\n" | "\n" | "\r" )
        bool 
        waxeye ::
        not_eol ( )
        {
            // clearly we could simplify here
            // but we won't, for the sake of clarity
            bool result = 
            ( 
                not_string ( "\r\n" ) &&
                not_string ( "\n"   ) &&
                not_string ( "\r"   )
            );
            return result;
        }
    }
}
