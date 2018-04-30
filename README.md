# Network-jammer

Network-jammer tries to search up every connected devices on the local network, and then starts to send deauthentication packets to all of them synchronously. It works as if it jams the wifi, as it prevents other devices from pinging the network. 

It also includes a white-list, which the tool user can create to let those devices be safe from the deauth attack.

It is a C++11 automated tool to jam all wifi clients within range and disconnect from their Access Point. Starting with available Wifi networks discovery, it injects Deauthenticaton packets to BSSID. Theory behind this: As we know, to disconnect from a connected wifi Access Point, we have to send a Deauth packet to the AP. Here, we will send a false Deauth packet in which the source MAC address is the MAC of the device that we want to jam on it (broadcast to disconnect all wifi clients) and the target is the BSSID's MAC.

Hope you enjoy the maximum bandwidth. :)