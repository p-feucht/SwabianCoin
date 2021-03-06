/*
 * This file is part of SwabianCoin.
 *
 * SwabianCoin is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * SwabianCoin is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with SwabianCoin.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef FULL_NODE_P2PCONNECTORSTUB_H
#define FULL_NODE_P2PCONNECTORSTUB_H

#include "IP2PConnector.h"

namespace scn {

    class P2PConnectorStub : public IP2PConnector {
    public:
        P2PConnectorStub()
        :num_connected_peers(10)
        ,callback_baseline_(NULL)
        ,callback_collection_(NULL) {};

        virtual ~P2PConnectorStub() {};

        virtual void connect() {

        }

        virtual void disconnect() {

        }

        virtual uint32_t numConnectedPeers() const {
            return num_connected_peers;
        }

        virtual void registerBlockCallbacks(std::function<void(IPeer&, const BaselineBlock&,bool)> callback_baseline,
                                            std::function<void(IPeer&, const CollectionBlock&,bool)> callback_collection) {
            callback_baseline_ = callback_baseline;
            callback_collection_ = callback_collection;
        }

        virtual void askForBlock(block_uid_t uid) {
            ask_for_block_counter_++;
            ask_for_block_uid_ = uid;
        }

        virtual void askForLastBaselineBlock() {
            ask_for_last_baseline_block_counter_++;
        }

        virtual void propagateBlock(const BaselineBlock& block) {
            propagate_baseline_block_counter_++;
        }

        virtual void propagateBlock(const CollectionBlock& block) {
            propagate_collection_block_counter_++;
        }

        uint32_t num_connected_peers;
        std::function<void(IPeer&, const BaselineBlock&,bool)> callback_baseline_;
        std::function<void(IPeer&, const CollectionBlock&,bool)> callback_collection_;

        uint32_t ask_for_block_counter_;
        uint32_t ask_for_last_baseline_block_counter_;
        uint32_t propagate_baseline_block_counter_;
        uint32_t propagate_collection_block_counter_;
        block_uid_t ask_for_block_uid_;
    };

}

#endif //FULL_NODE_P2PCONNECTORSTUB_H
