// //token
// v. 0.3.0
//
// Author: Cayden Lund
//   Date: 10/28/2021
//
// This file is part of sparkdown, a new markup/markdown language
// for quickly writing and formatting notes.
//
// This file contains the headers for the Token class.
//
// Copyright (C) 2021 Cayden Lund <https://github.com/shrimpster00>
// License: MIT <https://opensource.org/licenses/MIT>

#ifndef TOKEN_HPP
#define TOKEN_HPP

// System imports.
#include <string>
#include <regex>

// The sparkdown namespace contains all the classes and methods of the sparkdown library.
namespace sparkdown
{
    // An enumeration of the possible token types.
    enum token_type
    {
        SPACE,  // A space.
        DOLLAR, // A dollar sign.
        COLON,  // A colon.
        HASH,   // A hash.
        STAR,   // An asterisk.
        DASH,   // A dash.
        EQUALS, // An equals sign.
        ESCAPE, // A backslash.
        NUMBER, // A numeral.
        IGNORE  // A string that should be passed through as-is.
    };

    // Token.
    // This class is the token class, used to store the type and value of a token.
    // The Lexer class will create a list of tokens from a string.
    // These tokens are then used by the Parser class to parse the input line into LaTeX code.
    // Tokens are immutable; once instantiated, their values are read-only.
    class Token
    {
    public:
        // The constructor saves the type and value of the token.
        //
        // * const token_type &type        - The type of the token.
        // * const std::string_view &value - The value of the token.
        Token(const token_type &type, const std::string_view &value = "");

        // The get_type method returns the type of the token.
        //
        // * return token_type - The type of the token.
        token_type get_type();

        // The get_value method returns the value of the token.
        //
        // * return std::string_view - The value of the token.
        std::string_view get_value();

        // Override the == operator to compare two tokens.
        //
        // * Token other - The token to compare to.
        // * return bool  - Whether the two tokens are equal.
        bool operator==(const Token &other);

        // Override the != operator to compare two tokens.
        //
        // * Token other - The token to compare to.
        // * return bool  - Whether the two tokens are not equal.
        bool operator!=(const Token &other);

        // ==========================
        // | Public static methods. |
        // ==========================

        // The get_token_type method returns the string representation of the token type.
        //
        // * const token_type &type    - The type of the token.
        // * return std::string - The string representation of the token type.
        static std::string get_token_type(const token_type &type);

        // The tokens_equal method returns whether two vectors of tokens are equal.
        //
        // * const std::vector<Token> &tokens1 - The first vector of tokens.
        // * const std::vector<Token> &tokens2 - The second vector of tokens.
        // * return bool                       - Whether the two vectors of tokens are equal.
        static bool tokens_equal(const std::vector<Token> &tokens1, const std::vector<Token> &tokens2);

        // The print_tokens method returns the string representation of a vector of tokens.
        //
        // * const std::vector<Token> &tokens - The vector of tokens to print.
        // * return std::string               - The string representation of the vector of tokens.
        static std::string print_tokens(const std::vector<Token> &tokens);

    protected:
        // The type of the token.
        token_type type;

        // The value of the token.
        std::string_view value;
    };
}

#endif