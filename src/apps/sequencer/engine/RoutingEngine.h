#pragma once

#include "Config.h"

#include "MidiPort.h"

#include "model/Model.h"

#include "core/midi/MidiMessage.h"

#include <array>

#include <cstdint>

class Engine;

class RoutingEngine {
public:
    RoutingEngine(Engine &engine, Model &model);

    void update();

    bool receiveMidi(MidiPort port, const MidiMessage &message);

private:
    void updateSources();
    void updateSinks();

    void writeEngineTarget(Routing::Target target, float normalized);

    Engine &_engine;
    Routing &_routing;

    std::array<float, CONFIG_ROUTE_COUNT> _sourceValues;
};
