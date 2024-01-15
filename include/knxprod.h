#pragma once


#define paramDelay(time) (uint32_t)( \
            (time & 0xC000) == 0xC000 ? (time & 0x3FFF) * 100 : \
            (time & 0xC000) == 0x0000 ? (time & 0x3FFF) * 1000 : \
            (time & 0xC000) == 0x4000 ? (time & 0x3FFF) * 60000 : \
            (time & 0xC000) == 0x8000 ? ((time & 0x3FFF) > 1000 ? 3600000 : \
                                         (time & 0x3FFF) * 3600000 ) : 0 )
                                             
#define MAIN_OpenKnxId 0xA1
#define MAIN_ApplicationNumber 30
#define MAIN_ApplicationVersion 41
#define MAIN_ParameterSize 177
#define MAIN_MaxKoNumber 0
#define MAIN_OrderNumber "SYS-REG1-IP-Router"
// Parameter with single occurrence


#define BASE_StartupDelayBase                     0      // 2 Bits, Bit 7-6
#define     BASE_StartupDelayBaseMask 0xC0
#define     BASE_StartupDelayBaseShift 6
#define BASE_StartupDelayTime                     0      // 14 Bits, Bit 13-0
#define     BASE_StartupDelayTimeMask 0x3FFF
#define     BASE_StartupDelayTimeShift 0
#define BASE_Watchdog                             5      // 1 Bit, Bit 6
#define     BASE_WatchdogMask 0x40
#define     BASE_WatchdogShift 6

// Zeitbasis
#define ParamBASE_StartupDelayBase                    ((knx.paramByte(BASE_StartupDelayBase) & BASE_StartupDelayBaseMask) >> BASE_StartupDelayBaseShift)
// Zeit
#define ParamBASE_StartupDelayTime                    (knx.paramWord(BASE_StartupDelayTime) & BASE_StartupDelayTimeMask)
// Zeit (in Millisekunden)
#define ParamBASE_StartupDelayTimeMS                  (paramDelay(knx.paramWord(BASE_StartupDelayTime)))
// Watchdog aktivieren
#define ParamBASE_Watchdog                            ((bool)(knx.paramByte(BASE_Watchdog) & BASE_WatchdogMask))

#define NET_HostAddress                          6      // IP address, 4 Byte
#define NET_SubnetMask                          10      // IP address, 4 Byte
#define NET_GatewayAddress                      14      // IP address, 4 Byte
#define NET_NameserverAddress                   18      // IP address, 4 Byte
#define NET_WifiSSID                            22      // char*, 32 Byte
#define NET_WifiPassword                        54      // char*, 63 Byte
#define NET_CustomHostname                      117      // 1 Bit, Bit 7
#define     NET_CustomHostnameMask 0x80
#define     NET_CustomHostnameShift 7
#define NET_StaticIP                            117      // 1 Bit, Bit 6
#define     NET_StaticIPMask 0x40
#define     NET_StaticIPShift 6
#define NET_CustomMacAddress                    117      // 1 Bit, Bit 5
#define     NET_CustomMacAddressMask 0x20
#define     NET_CustomMacAddressShift 5
#define NET_mDNS                                118      // 1 Bit, Bit 7
#define     NET_mDNSMask 0x80
#define     NET_mDNSShift 7
#define NET_HTTP                                118      // 1 Bit, Bit 6
#define     NET_HTTPMask 0x40
#define     NET_HTTPShift 6
#define NET_NTP                                 118      // 1 Bit, Bit 5
#define     NET_NTPMask 0x20
#define     NET_NTPShift 5
#define NET_HostName                            119      // char*, 24 Byte
#define NET_MacAddress                          143      // char*, 17 Byte
#define NET_LanMode                             160      // 4 Bits, Bit 7-4
#define     NET_LanModeMask 0xF0
#define     NET_LanModeShift 4
#define NET_NetworkType                         160      // 4 Bits, Bit 3-0
#define     NET_NetworkTypeMask 0x0F
#define     NET_NetworkTypeShift 0
#define NET_Dummy                               176      // uint8_t

// IP-Adresse
#define ParamNET_HostAddress                         (knx.paramInt(NET_HostAddress))
// Subnetzsmaske
#define ParamNET_SubnetMask                          (knx.paramInt(NET_SubnetMask))
// Standardgateway
#define ParamNET_GatewayAddress                      (knx.paramInt(NET_GatewayAddress))
// Nameserver
#define ParamNET_NameserverAddress                   (knx.paramInt(NET_NameserverAddress))
// SSID
#define ParamNET_WifiSSID                            (knx.paramData(NET_WifiSSID))
// Passswort
#define ParamNET_WifiPassword                        (knx.paramData(NET_WifiPassword))
// Hostname anpassen
#define ParamNET_CustomHostname                      ((bool)(knx.paramByte(NET_CustomHostname) & NET_CustomHostnameMask))
// DHCP
#define ParamNET_StaticIP                            ((bool)(knx.paramByte(NET_StaticIP) & NET_StaticIPMask))
// MAC-Adresse anpassen
#define ParamNET_CustomMacAddress                    ((bool)(knx.paramByte(NET_CustomMacAddress) & NET_CustomMacAddressMask))
// mDNS
#define ParamNET_mDNS                                ((bool)(knx.paramByte(NET_mDNS) & NET_mDNSMask))
// Weberver
#define ParamNET_HTTP                                ((bool)(knx.paramByte(NET_HTTP) & NET_HTTPMask))
// Zeitgeber (NTP)
#define ParamNET_NTP                                 ((bool)(knx.paramByte(NET_NTP) & NET_NTPMask))
// Hostname
#define ParamNET_HostName                            (knx.paramData(NET_HostName))
// MAC-Adresse
#define ParamNET_MacAddress                          (knx.paramData(NET_MacAddress))
// LAN-Modus
#define ParamNET_LanMode                             ((knx.paramByte(NET_LanMode) & NET_LanModeMask) >> NET_LanModeShift)
// Typ
#define ParamNET_NetworkType                         (knx.paramByte(NET_NetworkType) & NET_NetworkTypeMask)
// 
#define ParamNET_Dummy                               (knx.paramByte(NET_Dummy))

#define TUNNEL_ChannelCount 4

// Parameter per channel
#define TUNNEL_ParamBlockOffset 0
#define TUNNEL_ParamBlockSize -1
#define TUNNEL_ParamCalcIndex(index) (index + TUNNEL_ParamBlockOffset + _channelIndex * TUNNEL_ParamBlockSize)





// Header generation for Module 'BASE_KommentarModule'

#define BASE_KommentarModuleCount 0
#define BASE_KommentarModuleModuleParamSize 0
#define BASE_KommentarModuleSubmodulesParamSize 0
#define BASE_KommentarModuleParamSize 0
#define BASE_KommentarModuleParamOffset 177
#define BASE_KommentarModuleCalcIndex(index, m1) (index + BASE_KommentarModuleParamOffset + _channelIndex * BASE_KommentarModuleCount * BASE_KommentarModuleParamSize + m1 * BASE_KommentarModuleParamSize)



