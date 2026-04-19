"""Loads waypoint lists from YAML files."""

from pathlib import Path
from typing import List

import yaml

from auto_nav_pioneer_interfaces.msg import Waypoint


def load_waypoints_from_yaml(yaml_path: str) -> List[Waypoint]:
    """Parse a YAML file into a list of Waypoint messages.

    Expected YAML structure:
        waypoints:
          - id: 0
            x: 5.0
            y: 0.0
            arrival_tolerance: 1.5
            requires_photo: true
            cone_side: "right"
          ...
    """
    path = Path(yaml_path).expanduser().resolve()
    if not path.exists():
        raise FileNotFoundError(f"Waypoint file not found: {path}")

    with open(path, 'r') as f:
        data = yaml.safe_load(f)

    if 'waypoints' not in data:
        raise ValueError(f"YAML must have a 'waypoints' key at top level")

    waypoints = []
    for i, entry in enumerate(data['waypoints']):
        wp = Waypoint()
        wp.id = entry['id']
        wp.x = float(entry['x'])
        wp.y = float(entry['y'])
        wp.arrival_tolerance = float(entry['arrival_tolerance'])
        wp.requires_photo = bool(entry['requires_photo'])
        wp.cone_side = str(entry['cone_side'])

        # Sanity check
        if wp.cone_side not in ('left', 'right'):
            raise ValueError(
                f"Waypoint {i}: cone_side must be 'left' or 'right', "
                f"got '{wp.cone_side}'")
        if wp.arrival_tolerance <= 0:
            raise ValueError(
                f"Waypoint {i}: arrival_tolerance must be positive")

        waypoints.append(wp)

    return waypoints