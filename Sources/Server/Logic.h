// Copyright 2023 Advanced Micro Devices, Inc
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "Channel.h"

#include <Logger/Logger.h>
#include <Networking/WebsocketServer.h>

class Logic : public RenderStudio::Networking::IServerLogic
{
public:
    void OnConnected(ConnectionPtr connection) override;
    void OnDisconnected(ConnectionPtr connection) override;
    void OnMessage(ConnectionPtr connection, const std::string& message);

private:
    void DebugPrint() const;
    std::optional<RenderStudio::API::Event> ParseEvent(const std::string& message);

    std::map<std::string, Channel> mChannels;
    std::mutex mMutex;
};
