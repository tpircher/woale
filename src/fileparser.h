/* Copyright (C) 2016  Thomas Pircher <tehpeh-web@tty1.net>
 *
 * woale -- a wiki engine.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * \file
 * Configuration file parser.
 */

#ifndef WOALE_FILEPARSER_H
#define WOALE_FILEPARSER_H


#include <string>


namespace woale {

    /**
     * Generic configuration file parser class.
     */
    class FileParser {
        public:
            /**
             * Virtual destructor.
             */
            virtual ~FileParser()
            {
            }

            /**
             * Parse the file.
             * \param[in] file_name the path to the file to parse.
             */
            void parse(const char *file_name);


        private:
            /**
             * The state of the file parser.
             */
            enum State {
                NONE,           //!< idle state.
                COMMENT,        //!< currently in a comment.
                ID,             //!< parsing an identifier.
                SEARCH_EQ,      //!< expecting an equal sign.
                SEARCH_VALUE,   //!< expecting a value.
                VALUE,          //!< parsing a value (rhs of the equals sign).
                STR_VALUE,      //!< parsing a string value.
                SEARCH_EOL,     //!< expect an end-of-line.
            };

            /**
             * Add a {key, val} tuple.
             */
            virtual void add_key_val(const std::string& key, const std::string &val) = 0;
    };

};

#endif  // WOALE_FILEPARSER_H
