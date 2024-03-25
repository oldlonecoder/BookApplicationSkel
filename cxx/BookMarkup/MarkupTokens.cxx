//
// Created by oldlonecoder on 25/03/24.
//

#include "BookMarkup/MarkupTokens.h"

using namespace lex;

namespace Book
{

size_t MarkupTokens::DeclareTable()
{
    Ref = TokenInfo::Array{
        {
            .Prim  = Type::Punc,
            .Sem   = Type::Keyword|Type::Punc,
            .M     = Mnemonic::BeginMarkup,
            .D     = Oper::Identifier,
            .Loc   = { .Begin                 = Lexem::BeginMarkup },
            .Flags = { .V                     = 0 }
        },
        {
            .Prim  = Type::Keyword,
            .Sem   = Type::Keyword|Type::Punc,
            .M     = Mnemonic::EndMarkup,
            .D     = Oper::Identifier,
            .Loc   = { .Begin            = Lexem::EndMarkup },
            .Flags = { .V                = 0 }
        },
        {
            .Prim  = Type::Keyword,
            .Sem   = Type::Keyword,
            .M     = Mnemonic::ForeGround,
            .D     = Oper::Identifier,
            .Loc   = {. Begin             = Lexem::ForeGround},
            .Flags = { .V                 = 0 }
        },
        {
            .Prim  = Type::Keyword,
            .Sem   = Type::Keyword,
            .M     = Mnemonic::BackGround,
            .D     = Oper::Identifier,
            .Loc   = {. Begin             = Lexem::BackGround},
            .Flags = { .V                 = 0 }
        },
        {
            .Prim  = Type::Keyword,
            .Sem   = Type::Keyword,
            .M     = Mnemonic::Icon,
            .D     = Oper::Identifier,
            .Loc   = {. Begin             = Lexem::Icon},
            .Flags = { .V                 = 0 }
        },
        {
            .Prim  = Type::Keyword,
            .Sem   = Type::Keyword,
            .M     = Mnemonic::Accent,
            .D     = Oper::Identifier,
            .Loc   = {. Begin             = Lexem::Accent},
            .Flags = { .V                 = 0 }
        },
        {
            .Prim  = Type::Punc,
            .Sem   = Type::Punc,
            .M     = Mnemonic::AttrSeq,
            .D     = Oper::Identifier,
            .Loc   = {. Begin             = Lexem::AttrSeq},
            .Flags = { .V                 = 0 }
        },
        {
            .Prim  = Type::Keyword,
            .Sem   = Type::Keyword,
            .M     = Mnemonic::ColorPair,
            .D     = Oper::Identifier,
            .Loc   = {. Begin             = Lexem::ColorPair},
            .Flags = { .V                 = 0 }
        },
        {
            .Prim  = Type::Keyword,
            .Sem   = Type::Keyword,
            .M     = Mnemonic::Reset,
            .D     = Oper::Identifier,
            .Loc   = {. Begin             = Lexem::Reset},
            .Flags = { .V                 = 0 }
        },
        {
            .Prim  = Type::Punc,
            .Sem   = Type::Punc,
            .M     = Mnemonic::ArgSep,
            .D     = Oper::Identifier,
            .Loc   = {. Begin             = Lexem::ArgSep},
            .Flags = { .V                 = 0 }
        },
        {
            .Prim  = Type::Keyword,
            .Sem   = Type::Keyword,
            .M     = Mnemonic::LineBreak,
            .D     = Oper::Identifier,
            .Loc   = {. Begin             = Lexem::LineBreak},
            .Flags = { .V                 = 0 }
        },
        {
            .Prim  = Type::Keyword,
            .Sem   = Type::Keyword,
            .M     = Mnemonic::Left,
            .D     = Oper::Identifier,
            .Loc   = {. Begin             = Lexem::Left},
            .Flags = { .V                 = 0 }
        },
        {
            .Prim  = Type::Keyword,
            .Sem   = Type::Keyword,
            .M     = Mnemonic::Right,
            .D     = Oper::Identifier,
            .Loc   = {. Begin             = Lexem::Right},
            .Flags = { .V                 = 0 }
        },
        {
            .Prim  = Type::Keyword,
            .Sem   = Type::Keyword,
            .M     = Mnemonic::Top,
            .D     = Oper::Identifier,
            .Loc   = {. Begin             = Lexem::Top},
            .Flags = { .V                 = 0 }
        },
        {
            .Prim  = Type::Keyword,
            .Sem   = Type::Keyword,
            .M     = Mnemonic::Bottom,
            .D     = Oper::Identifier,
            .Loc   = {. Begin             = Lexem::Bottom},
            .Flags = { .V                 = 0 }
        },
        {
            .Prim  = Type::Keyword,
            .Sem   = Type::Keyword,
            .M     = Mnemonic::Center,
            .D     = Oper::Identifier,
            .Loc   = {. Begin             = Lexem::Center},
            .Flags = { .V                 = 0 }
        },
        {
            .Prim  = Type::Keyword,
            .Sem   = Type::Keyword,
            .M     = Mnemonic::HVCenter,
            .D     = Oper::Identifier,
            .Loc   = {. Begin             = Lexem::HVCenter},
            .Flags = { .V                 = 0 }
        },
        {
            .Prim  = Type::Keyword,
            .Sem   = Type::Keyword,
            .M     = Mnemonic::Box,
            .D     = Oper::Identifier,
            .Loc   = {. Begin             = Lexem::Box},
            .Flags = { .V                 = 0 }
        }
    };


    return Ref.size();
}
} // Book