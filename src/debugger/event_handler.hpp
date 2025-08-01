#pragma once

#include <windows_emulator.hpp>

namespace debugger
{
    enum class emulation_state
    {
        none,
        running,
        paused,
    };

    struct event_context
    {
        windows_emulator& win_emu;
        emulation_state state{emulation_state::none};
    };

    void handle_events(event_context& c);
    void handle_exit(const windows_emulator& win_emu, std::optional<NTSTATUS> exit_status);
    void update_emulation_status(const windows_emulator& win_emu);
}
