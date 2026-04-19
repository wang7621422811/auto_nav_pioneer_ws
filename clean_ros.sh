#!/usr/bin/env bash
set -euo pipefail

# Clean build artifacts in a ROS 2 workspace.
# Usage:
#   ./clean_ros.sh [workspace_path]
# Example:
#   ./clean_ros.sh ~/workspace/auto_nav_pioneer_ws

WS_DIR="${1:-$HOME/workspace/auto_nav_pioneer_ws}"

if [ ! -d "$WS_DIR" ]; then
  echo "Error: workspace not found: $WS_DIR" >&2
  exit 1
fi

cd "$WS_DIR"

echo "Cleaning ROS 2 workspace: $WS_DIR"
rm -rf build install log

echo "Done. Removed: build install log"
echo "You can rebuild with:"
echo "  cd $WS_DIR && colcon build"