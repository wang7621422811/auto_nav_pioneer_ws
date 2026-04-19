"""Gamepad profiles for different controllers."""

from dataclasses import dataclass
from typing import Optional


@dataclass(frozen=True)
class GamepadProfile:
    name: str

    # --- Mode buttons (always digital) ---
    btn_enable_auto: int       # "X" on PS4, "B" on Switch
    btn_enable_manual: int     # "O" on PS4, "A" on Switch

    # --- Sticks (always analog) ---
    axis_forward: int          # Left stick Y
    axis_turn: int             # Right stick X

    # --- Dead-man trigger: EITHER axis OR button ---
    # If trigger is analog (PS4): set axis index + threshold, leave button = None
    # If trigger is digital (Switch clone): set button index, leave axis = None
    l2_axis: Optional[int]
    l2_button: Optional[int]
    r2_axis: Optional[int]
    r2_button: Optional[int]
    trigger_pressed_threshold: float = -0.5  # Only used for analog


# ------------------- Profile definitions -------------------

XBOX360_PROFILE = GamepadProfile(
    name="switch_pro",
    btn_enable_auto=0,
    btn_enable_manual=1,
    axis_forward=1,
    axis_turn=3,
    l2_axis=None,     # Digital — use button
    l2_button=6,
    r2_axis=None,
    r2_button=7,
)

SWITCH_PRO_NATIVE_PROFILE = GamepadProfile(
    name="switch_pro_native",
    btn_enable_auto=0,       # B button
    btn_enable_manual=1,     # A button
    axis_forward=1,          # Left stick Y
    axis_turn=2,             # Right stick X — different from Xbox!
    l2_axis=None,
    l2_button=6,             # ZL as digital button
    r2_axis=None,
    r2_button=7,             # ZR as digital button
)

PS4_PROFILE = GamepadProfile(
    name="ps4",
    btn_enable_auto=0,
    btn_enable_manual=1,
    axis_forward=1,
    axis_turn=3,
    l2_axis=2,        # Analog — use axis
    l2_button=None,
    r2_axis=5,
    r2_button=None,
)

# Registry for lookup by name
PROFILES = {
    "switch_pro_native": SWITCH_PRO_NATIVE_PROFILE,
    "xbox360": XBOX360_PROFILE,
    "ps4": PS4_PROFILE,
}


def get_profile(name: str) -> GamepadProfile:
    if name not in PROFILES:
        raise ValueError(
            f"Unknown gamepad profile '{name}'. "
            f"Available: {list(PROFILES.keys())}")
    return PROFILES[name]