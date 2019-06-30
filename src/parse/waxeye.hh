#ifndef xp__parse__waxeye_hh
#define xp__parse__waxeye_hh

#include <string>

namespace xp
{
    namespace parse
    {
        class waxeye
        {
        public:

            waxeye ( const waxeye & we )              = delete;
            waxeye & operator = ( const waxeye & we ) = delete;

            waxeye ( )                                = default;
            bool parse ( const std::string & text );

        private:
            std::string                 m_text;
            std::string::const_iterator m_text_pos;

            //
            // match rules
            //
            bool match_grammar ( );
            bool match_definition ( );
            bool match_alternation ( );
            bool match_sequence ( );
            bool match_unit ( );
            bool match_prefix ( );
            bool match_label ( );
            bool match_action ( );
            bool match_identifier ( );
            bool match_literal ( );
            bool match_i_case_leteral ( );
            bool match_char_class ( );
            bool match_char_range ( );
            bool match_char ( );
            bool match_hex_char ( );
            bool match_wild_card ( );
            bool match_left_arrow ( );
            bool match_prune_arrow ( );
            bool match_void_arrow ( );
            bool match_alt ( );
            bool match_open ( );
            bool match_close ( );
            bool match_comma ( );
            bool match_eol_comment ( );
            bool match_mul_comment ( );
            bool match_eol ( );
            bool match_ws ( );

            //
            // Parametised rules
            //
            bool match_char_class ( const char * char_class );
            bool match_string     ( const char * cstr );

            //
            // utilities
            //
            void set_text_pos ( const std::string::const_iterator text_pos );
        };
    }
}

#endif