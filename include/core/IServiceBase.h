//
// Created by felix lee on 2020/12/14.
//

#ifndef JUPITER_ISERVICE_BASE_H
#define JUPITER_ISERVICE_BASE_H

#include "ds.h"

namespace jupiter {
    class IServiceBase {

    public:
        virtual void Init() = 0;
        virtual void Dispose() = 0;
        void GetServiceName(std::string & name) {
            name = name_.GetValue();
        };
        virtual ~IServiceBase()= default;
    private:
        FIELD_16 name_;

    };
}



#endif //JUPITER_ISERVICE_BASE_H
