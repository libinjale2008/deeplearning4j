/*******************************************************************************
 * Copyright (c) 2015-2018 Skymind, Inc.
 *
 * This program and the accompanying materials are made available under the
 * terms of the Apache License, Version 2.0 which is available at
 * https://www.apache.org/licenses/LICENSE-2.0.
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 * SPDX-License-Identifier: Apache-2.0
 ******************************************************************************/

//
// Created by raver119 on 11/06/18.
//

#include <graph/ResultWrapper.h>
#include <stdexcept>


namespace sd {
    namespace graph {
        ResultWrapper::ResultWrapper(Nd4jLong size, Nd4jPointer ptr) {
            if (size <= 0)
                throw std::runtime_error("FlatResult size should be > 0");

            _size = size;
            _pointer = ptr;
        }

        ResultWrapper::~ResultWrapper() {
            if (_pointer != nullptr && _size > 0) {
                auto ptr = reinterpret_cast<char *>(_pointer);
                delete[] ptr;
            }
        }


        Nd4jLong ResultWrapper::size() {
            return _size;
        }

        Nd4jPointer ResultWrapper::pointer() {
            return _pointer;
        }
    }
}