# A single navigation target for the Pioneer robot.
# Coordinates are in the local 'odom' frame (meters).

uint32 id                          # Waypoint sequence number (0, 1, 2...)
float64 x                          # Target position X (meters)
float64 y                          # Target position Y (meters)
float64 arrival_tolerance          # Accept as "reached" within this radius (meters)
bool requires_photo                # Take a photo when arriving
string cone_side                   # "left" or "right" — which side to leave the cone