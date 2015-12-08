//
//  util.h
//  Degenerate
//
//  Created by Jarad DeLorenzo on 12/7/15.
//
//

#ifndef Degenerate_util_h
#define Degenerate_util_h

class Util {

public:
    template <typename T>
    static std::string to_string(T value) {
        std::ostringstream os ;
        os << value ;
        return os.str() ;
    }
};

#endif
