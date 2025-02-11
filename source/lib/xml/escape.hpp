//
// This is a derivative work. originally part of the LLVM Project.
// Licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
// Copyright (c) 2023 Vinnie Falco (vinnie.falco@gmail.com)
//
// Official repository: https://github.com/cppalliance/mrdox
//

#ifndef MRDOX_XML_ESCAPE_HPP
#define MRDOX_XML_ESCAPE_HPP

#include <llvm/ADT/StringRef.h>
#include <llvm/Support/raw_ostream.h>

namespace clang {
namespace mrdox {
namespace xml {

/** Manipulator to apply XML escaping to output.
*/
struct escape
{
    explicit
    escape(
        llvm::StringRef const& s) noexcept
        : s_(s)
    {
    }

    friend
    llvm::raw_ostream&
    operator<<(
        llvm::raw_ostream& os,
        escape const& t)
    {
        t.write(os);
        return os;
    }

private:
    void write(llvm::raw_ostream& os) const;

    llvm::StringRef s_;
};

} // xml
} // mrdox
} // clang

#endif
