#ifndef __LINUX_ES305B_PARAM_H_
#define __LINUX_ES305B_PARAM_H_

static const u8 incall_receiver_buf[] =
{
	0x80, 0x52, 0x00, 0x00, // disable digital pass through
	0x80, 0x26, 0x00, 0x01,	// select path route 0x0001
	0x80, 0X0C, 0x0A, 0X00, 0x80, 0X0D, 0x00, 0X0F, //; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x00: PCM WordLength0x800D: SetDeviceParm, 0x000F: 16 Bits
	0x80, 0X0C, 0x0A, 0X02, 0x80, 0X0D, 0x00, 0X00, //; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x02: PCM DelFromFsTx0x800D: SetDeviceParm, 0x0000: (0 clocks)
	0x80, 0X0C, 0x0A, 0X03, 0x80, 0X0D, 0x00, 0X01, //; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x03: PCM DelFromFsRx0x800D: SetDeviceParm, 0x0001: (1 clocks)
	0x80, 0X0C, 0x0A, 0X04, 0x80, 0X0D, 0x00, 0X02, //; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x04: PCM Latch Edge0x800D: SetDeviceParm, 0x0002:TxFalling/RxFalling
	0x80, 0X0C, 0x0A, 0X05, 0x80, 0X0D, 0x00, 0X01, //; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x05: PCM Endianness0x800D: SetDeviceParm, 0x0001:Big Endian
	0x80, 0X0C, 0x0A, 0X06, 0x80, 0X0D, 0x00, 0X00, //; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x06: PCM Tristate Enable0x800D: SetDeviceParm, 0x0000: Disable
	0x80, 0X0C, 0x0A, 0X07, 0x80, 0X0D, 0x00, 0X00, //; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x07: PCM Audio Port Mode0x800D: SetDeviceParm, 0x0000: PCM

	0x80, 0X0C, 0x0C, 0X00, 0x80, 0X0D, 0x00, 0X0F, //; 0x800C: SetDeviceParmID, 0x0C: PCM2, 0x00: PCM WordLength0x800D: SetDeviceParm, 0x000F: 16 Bits
	0x80, 0X0C, 0x0C, 0X02, 0x80, 0X0D, 0x00, 0X01, //; 0x800C: SetDeviceParmID, 0x0C: PCM2, 0x02: PCM DelFromFsTx0x800D: SetDeviceParm, 0x0001: (1 clocks)
	0x80, 0X0C, 0x0C, 0X03, 0x80, 0X0D, 0x00, 0X01, //; 0x800C: SetDeviceParmID, 0x0C: PCM2, 0x03: PCM DelFromFsRx0x800D: SetDeviceParm, 0x0001: (1 clocks)
	0x80, 0X0C, 0x0C, 0X04, 0x80, 0X0D, 0x00, 0X02, //; 0x800C: SetDeviceParmID, 0x0C: PCM2, 0x04: PCM Latch Edge0x800D: SetDeviceParm, 0x0002:TxFalling/RxFalling
	0x80, 0X0C, 0x0C, 0X05, 0x80, 0X0D, 0x00, 0X01, //; 0x800C: SetDeviceParmID, 0x0C: PCM2, 0x05: PCM Endianness0x800D: SetDeviceParm, 0x0001:Big Endian
	0x80, 0X0C, 0x0C, 0X06, 0x80, 0X0D, 0x00, 0X00, //; 0x800C: SetDeviceParmID, 0x0C: PCM2, 0x06: PCM Tristate Enable0x800D: SetDeviceParm, 0x0000: Disable
	0x80, 0X0C, 0x0C, 0X07, 0x80, 0X0D, 0x00, 0X00, //; 0x800C: SetDeviceParmID, 0x0C: PCM2, 0x07: PCM Audio Port Mode0x800D: SetDeviceParm, 0x0000: PCM

	0x80, 0X1C, 0x00, 0X01, //; 0x801C: VoiceProcessing, 0x0001:On, 0x0000:Off

	0x80, 0X1B, 0x00, 0X04, //; 0x801B: SetDigitalInputGain, 0x00: PCM-A left, 0x04: 4dB
	0x80, 0X1B, 0x01, 0X04, //; 0x801B: SetDigitalInputGain, 0x00: PCM-A right, 0x04: 4dB
	0x80, 0X1B, 0x04, 0X12, //; 0x801B: SetDigitalInputGain, 0x04: PCM-C left, 0x04: 18dB
	0x80, 0X15, 0x00, 0XE8, //; 0x8015: SetDigitalOutputGain, 0x00: PCM-A left, 0xE8: -24dB
	0x80, 0X15, 0x04, 0X0C, //; 0x8015: SetDigitalOutputGain, 0x00: PCM-C left, 0x0C: 12dB


	0x80, 0X17, 0x00, 0X1C, 0x80, 0X18, 0x00, 0X1F, //; 0x8017:SetAlgorithmParmID, 0x001C:0x8018:SetAlgorithmParm, 0x001F:Reset all
	0x80, 0X17, 0x00, 0X4B, 0x80, 0X18, 0x00, 0X06, //; 0x8017:SetAlgorithmParmID, 0x004B:Tx Noise Suppression Level, 0x8018:SetAlgorithmParm, 0x0006:Level 6
	0x80, 0X17, 0x00, 0X02, 0x80, 0X18, 0x00, 0X00, //; 0x8017:SetAlgorithmParmID, 0x0002:Microphone Configuration, 0x8018:SetAlgorithmParm, 0x0000:2-mic Close Talk (CT)
	0x80, 0X17, 0x00, 0X15, 0x80, 0X18, 0x00, 0X00, //; 0x8017:SetAlgorithmParmID, 0x0015:Side Tone Mode, 0x8018:SetAlgorithmParm, 0x0000:Off
	0x80, 0X17, 0x00, 0X16, 0x80, 0X18, 0xFF, 0XEE, //; 0x8017:SetAlgorithmParmID, 0x0016:   Side Tone Gain (dB), 0x8018:SetAlgorithmParm, 0xFFEE:(-18 dB)
	0x80, 0X17, 0x00, 0X03, 0x80, 0X18, 0x00, 0X01, //; 0x8017:SetAlgorithmParmID, 0x0003:AEC Mode, 0x8018:SetAlgorithmParm, 0x0001:AEC On (auto select mode)
	0x80, 0X17, 0x00, 0X12, 0x80, 0X18, 0x00, 0X00, //; 0x8017:SetAlgorithmParmID, 0x0012:   Downlink Speaker Volume, 0x8018:SetAlgorithmParm, 0x0000:(0 dB)
	0x80, 0X17, 0x00, 0X23, 0x80, 0X18, 0x00, 0X00, //; 0x8017:SetAlgorithmParmID, 0x0023:   Use AEC Comfort Noise Fill, 0x8018:SetAlgorithmParm, 0x0000:No
	0x80, 0X17, 0x00, 0X34, 0x80, 0X18, 0x00, 0X00, //; 0x8017:SetAlgorithmParmID, 0x0034:   Echo Suppression Enhancement, 0x8018:SetAlgorithmParm, 0x0000:(0 dB)
	0x80, 0X17, 0x00, 0X2E, 0x80, 0X18, 0xFF, 0XC4, //; 0x8017:SetAlgorithmParmID, 0x002E:   AEC Comfort Noise Gain, 0x8018:SetAlgorithmParm, 0xFFC4:(-60 dB)
	0x80, 0X17, 0x01, 0X03, 0x80, 0X18, 0x00, 0X00, //; 0x8017:SetAlgorithmParmID, 0x0103:   DT ESE Back Off, 0x8018:SetAlgorithmParm, 0:(0 dB)
	0x80, 0X17, 0x00, 0X04, 0x80, 0X18, 0x00, 0X00, //; 0x8017:SetAlgorithmParmID, 0x0004:Use AGC, 0x8018:SetAlgorithmParm, 0x0000:No
	0x80, 0X17, 0x00, 0X28, 0x80, 0X18, 0x00, 0X00, //; 0x8017:SetAlgorithmParmID, 0x0028:Use Rx AGC, 0x8018:SetAlgorithmParm, 0x0000:No
	0x80, 0X17, 0x00, 0X29, 0x80, 0X18, 0xFF, 0XE6, //; 0x8017:SetAlgorithmParmID, 0x0029:   Rx AGC Target Level (dB), 0x8018:SetAlgorithmParm, 0xFFE6:(-26 dB)
	0x80, 0X17, 0x00, 0X2A, 0x80, 0X18, 0xFF, 0XA6, //; 0x8017:SetAlgorithmParmID, 0x002A:   Rx AGC Noise Floor (dB), 0x8018:SetAlgorithmParm, 0xFFA6:(-90 dB)
	0x80, 0X17, 0x00, 0X2B, 0x80, 0X18, 0x00, 0X04, //; 0x8017:SetAlgorithmParmID, 0x002B:   Rx AGC SNR Improve (dB), 0x8018:SetAlgorithmParm, 0x0004:(4 dB)
	0x80, 0X17, 0x00, 0X2C, 0x80, 0X18, 0x00, 0X04, //; 0x8017:SetAlgorithmParmID, 0x002C:   Rx AGC Up Rate (dBS), 0x8018:SetAlgorithmParm, 0x0004:(4 dBS)
	0x80, 0X17, 0x00, 0X2D, 0x80, 0X18, 0x00, 0X04, //; 0x8017:SetAlgorithmParmID, 0x002D:   Rx AGC Down Rate (dBS), 0x8018:SetAlgorithmParm, 0x0004:(4 dBS)
	0x80, 0X17, 0x01, 0X02, 0x80, 0X18, 0x00, 0X0F, //; 0x8017:SetAlgorithmParmID, 0x0102:   Rx AGC Max Gain (dB), 0x8018:SetAlgorithmParm, 0x000F:(15 dB)
	0x80, 0X17, 0x00, 0X3F, 0x80, 0X18, 0x00, 0X00, //; 0x8017:SetAlgorithmParmID, 0x003F:   Rx AGC Guard Band (dB), 0x8018:SetAlgorithmParm, 0x0000:(0 dB)
	0x80, 0X17, 0x00, 0X09, 0x80, 0X18, 0x00, 0X00, //; 0x8017:SetAlgorithmParmID, 0x0009:Speaker Enhancement Mode, 0x8018:SetAlgorithmParm, 0x0000:SE Off (HPF only)
	0x80, 0X17, 0x00, 0X0E, 0x80, 0X18, 0x00, 0X01, //; 0x8017:SetAlgorithmParmID, 0x000E:Far End Noise Suppression, 0x8018:SetAlgorithmParm, 0x0001:On (auto select mode)
	0x80, 0X17, 0x00, 0X4C, 0x80, 0X18, 0x00, 0X04, //; 0x8017:SetAlgorithmParmID, 0x004C:   Rx Noise Suppression Level, 0x8018:SetAlgorithmParm, 0x0004:Level 4
	0x80, 0X17, 0x00, 0X20, 0x80, 0X18, 0x00, 0X01, //; 0x8017:SetAlgorithmParmID, 0x0020:Tx PostEq Mode, 0x8018:SetAlgorithmParm, 0x0001:On
	0x80, 0X17, 0x00, 0X1F, 0x80, 0X18, 0x00, 0X01, //; 0x8017:SetAlgorithmParmID, 0x001F:Rx PostEq Mode, 0x8018:SetAlgorithmParm, 0x0001:On
	0x80, 0X17, 0x00, 0X30, 0x80, 0X18, 0x00, 0X00, //; 0x8017:SetAlgorithmParmID, 0x0030:Tx MBC Mode, 0x8018:SetAlgorithmParm, 0x0000:Off
	0x80, 0X17, 0x00, 0X31, 0x80, 0X18, 0x00, 0X00, //; 0x8017:SetAlgorithmParmID, 0x0031:Rx MBC Mode, 0x8018:SetAlgorithmParm, 0x0000:Off
	0x80, 0X17, 0x00, 0X1A, 0x80, 0X18, 0x00, 0X01, //; 0x8017:SetAlgorithmParmID, 0x001A:Use Tx ComfortNoise, 0x8018:SetAlgorithmParm, 0x0001:Yes
	0x80, 0X17, 0x00, 0X1B, 0x80, 0X18, 0xFF, 0XB5, //; 0x8017:SetAlgorithmParmID, 0x001B:   Tx ComfortNoise gain (dB), 0x8018:SetAlgorithmParm, 0xFFB5:(-75 dB)
	0x80, 0X17, 0x00, 0X1E, 0x80, 0X18, 0x00, 0X01, //; 0x8017:SetAlgorithmParmID, 0x001E:PST, 0x8018:SetAlgorithmParm, 0x0001:1
};

static const u8 incall_speaker_buf[] =
{
	0x80, 0x52, 0x00, 0x00, // disable digital pass through
	0x80, 0x26, 0x00, 0x01,	// select path route 0x0001
	0x80, 0X0C, 0x0A, 0X00, 0x80, 0X0D, 0x00, 0X0F, //; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x00: PCM WordLength0x800D: SetDeviceParm, 0x000F: 16 Bits
	0x80, 0X0C, 0x0A, 0X02, 0x80, 0X0D, 0x00, 0X00, //; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x02: PCM DelFromFsTx0x800D: SetDeviceParm, 0x0000: (0 clocks)
	0x80, 0X0C, 0x0A, 0X03, 0x80, 0X0D, 0x00, 0X01, //; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x03: PCM DelFromFsRx0x800D: SetDeviceParm, 0x0001: (1 clocks)
	0x80, 0X0C, 0x0A, 0X04, 0x80, 0X0D, 0x00, 0X02, //; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x04: PCM Latch Edge0x800D: SetDeviceParm, 0x0002:TxFalling/RxFalling
	0x80, 0X0C, 0x0A, 0X05, 0x80, 0X0D, 0x00, 0X01, //; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x05: PCM Endianness0x800D: SetDeviceParm, 0x0001:Big Endian
	0x80, 0X0C, 0x0A, 0X06, 0x80, 0X0D, 0x00, 0X00, //; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x06: PCM Tristate Enable0x800D: SetDeviceParm, 0x0000: Disable
	0x80, 0X0C, 0x0A, 0X07, 0x80, 0X0D, 0x00, 0X00, //; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x07: PCM Audio Port Mode0x800D: SetDeviceParm, 0x0000: PCM

	0x80, 0X0C, 0x0C, 0X00, 0x80, 0X0D, 0x00, 0X0F, //; 0x800C: SetDeviceParmID, 0x0C: PCM2, 0x00: PCM WordLength0x800D: SetDeviceParm, 0x000F: 16 Bits
	0x80, 0X0C, 0x0C, 0X02, 0x80, 0X0D, 0x00, 0X01, //; 0x800C: SetDeviceParmID, 0x0C: PCM2, 0x02: PCM DelFromFsTx0x800D: SetDeviceParm, 0x0001: (1 clocks)
	0x80, 0X0C, 0x0C, 0X03, 0x80, 0X0D, 0x00, 0X01, //; 0x800C: SetDeviceParmID, 0x0C: PCM2, 0x03: PCM DelFromFsRx0x800D: SetDeviceParm, 0x0001: (1 clocks)
	0x80, 0X0C, 0x0C, 0X04, 0x80, 0X0D, 0x00, 0X02, //; 0x800C: SetDeviceParmID, 0x0C: PCM2, 0x04: PCM Latch Edge0x800D: SetDeviceParm, 0x0002:TxFalling/RxFalling
	0x80, 0X0C, 0x0C, 0X05, 0x80, 0X0D, 0x00, 0X01, //; 0x800C: SetDeviceParmID, 0x0C: PCM2, 0x05: PCM Endianness0x800D: SetDeviceParm, 0x0001:Big Endian
	0x80, 0X0C, 0x0C, 0X06, 0x80, 0X0D, 0x00, 0X00, //; 0x800C: SetDeviceParmID, 0x0C: PCM2, 0x06: PCM Tristate Enable0x800D: SetDeviceParm, 0x0000: Disable
	0x80, 0X0C, 0x0C, 0X07, 0x80, 0X0D, 0x00, 0X00, //; 0x800C: SetDeviceParmID, 0x0C: PCM2, 0x07: PCM Audio Port Mode0x800D: SetDeviceParm, 0x0000: PCM

	0x80, 0X1C, 0x00, 0X01, // 0x801C: VoiceProcessing, 0x0001:On, 0x0000:Off
	0x80, 0X1B, 0x00, 0X0B, // 0x801B:SetDigitalInputGain, 0x00:PCM-A left, 0x0B:(11 dB)
	0x80, 0X1B, 0x01, 0X00, // 0x801B:SetDigitalInputGain, 0x01:PCM-A right, 0x00:(0 dB)
	0x80, 0X1B, 0x04, 0X0F, // 0x801B:SetDigitalInputGain, 0x04:PCM-C left, 0x0F:(15 dB)
	0x80, 0X15, 0x00, 0XEA, // 0x801B:SetDigitalOutputGain, 0x00:PCM-A left, 0xEA:(-22 dB)

	0x80, 0X17, 0x00, 0X03, 0x80, 0X18, 0x00, 0X01, //; 0x8017:SetAlgorithmParmID, 0x0003:AEC Mode, 0x8018:SetAlgorithmParm, 0x0001:AEC On (auto select mode)
	0x80, 0X17, 0x00, 0X12, 0x80, 0X18, 0x00, 0X01, //; 0x8017:SetAlgorithmParmID, 0x0012:   Downlink Speaker Volume, 0x8018:SetAlgorithmParm, 0x00001:(1 dB)
	0x80, 0X17, 0x00, 0X23, 0x80, 0X18, 0x00, 0X00, //; 0x8017:SetAlgorithmParmID, 0x0023:   Use AEC Comfort Noise Fill, 0x8018:SetAlgorithmParm, 0x0000:No
	0x80, 0X17, 0x00, 0X34, 0x80, 0X18, 0x00, 0X05, //; 0x8017:SetAlgorithmParmID, 0x0034:   Echo Suppression Enhancement, 0x8018:SetAlgorithmParm, 0x0005:(5 dB)
	0x80, 0X17, 0x00, 0X2E, 0x80, 0X18, 0xFF, 0XD3, //; 0x8017:SetAlgorithmParmID, 0x002E:   AEC Comfort Noise Gain, 0x8018:SetAlgorithmParm, 0xFFD3:(-45 dB)
	0x80, 0X17, 0x01, 0X03, 0x80, 0X18, 0xFF, 0XFB, //; 0x8017:SetAlgorithmParmID, 0x0103:   DT ESE Back Off, 0x8018:SetAlgorithmParm, 0xFFFB:(-5 dB)
	0x80, 0X17, 0x00, 0X04, 0x80, 0X18, 0x00, 0X01, //; 0x8017:SetAlgorithmParmID, 0x0004:Use Tx AGC, 0x8018:SetAlgorithmParm, 0x0001:Yes
	0x80, 0X17, 0x00, 0X05, 0x80, 0X18, 0xFF, 0XE9, //; 0x8017:SetAlgorithmParmID, 0x0005:   AGC Target Level (dB), 0x8018:SetAlgorithmParm, 0xFFE9:(-23 dB)
	0x80, 0X17, 0x00, 0X06, 0x80, 0X18, 0xFF, 0XC4, //; 0x8017:SetAlgorithmParmID, 0x0006:   AGC Noise Floor (dB), 0x8018:SetAlgorithmParm, 0xFFBF:(-60 dB)
	0x80, 0X17, 0x00, 0X07, 0x80, 0X18, 0x00, 0X04, //; 0x8017:SetAlgorithmParmID, 0x0007:   AGC SNR Improve (dB), 0x8018:SetAlgorithmParm, 0x0004:(4 dB)
	0x80, 0X17, 0x00, 0X26, 0x80, 0X18, 0x00, 0X04, //; 0x8017:SetAlgorithmParmID, 0x0026:   AGC Up Rate (dBS), 0x8018:SetAlgorithmParm, 0x0004:(4 dBS)
	0x80, 0X17, 0x00, 0X27, 0x80, 0X18, 0x00, 0X04, //; 0x8017:SetAlgorithmParmID, 0x0027:   AGC Down Rate (dBS), 0x8018:SetAlgorithmParm, 0x0004:(4 dBS)
	0x80, 0X17, 0x01, 0X00, 0x80, 0X18, 0x00, 0X28, //; 0x8017:SetAlgorithmParmID, 0x0100:   AGC Max Gain (dB), 0x8018:SetAlgorithmParm, 0x0028:(40 dB)
	0x80, 0X17, 0x00, 0X28, 0x80, 0X18, 0x00, 0X00, //; 0x8017:SetAlgorithmParmID, 0x0028:Use Rx AGC, 0x8018:SetAlgorithmParm, 0x0000:No
	0x80, 0X17, 0x00, 0X09, 0x80, 0X18, 0x00, 0X00, //; 0x8017:SetAlgorithmParmID, 0x0009:Speaker Enhancement Mode, 0x8018:SetAlgorithmParm, 0x0000:SE Off (HPF only)
	0x80, 0X17, 0x00, 0X0E, 0x80, 0X18, 0x00, 0X01, //; 0x8017:SetAlgorithmParmID, 0x000E:Far End Noise Suppression, 0x8018:SetAlgorithmParm, 0x0001:On (auto select mode)
	0x80, 0X17, 0x00, 0X4C, 0x80, 0X18, 0x00, 0X05, //; 0x8017:SetAlgorithmParmID, 0x004C:   Rx Noise Suppression Level, 0x8018:SetAlgorithmParm, 0x0005:Level 5
	0x80, 0X17, 0x00, 0X20, 0x80, 0X18, 0x00, 0X01, //; 0x8017:SetAlgorithmParmID, 0x0020:Tx PostEq Mode, 0x8018:SetAlgorithmParm, 0x0001:On
	0x80, 0X17, 0x00, 0X1F, 0x80, 0X18, 0x00, 0X01, //; 0x8017:SetAlgorithmParmID, 0x001F:Rx PostEq Mode, 0x8018:SetAlgorithmParm, 0x000n:On
	0x80, 0X17, 0x00, 0X30, 0x80, 0X18, 0x00, 0X00, //; 0x8017:SetAlgorithmParmID, 0x0030:Tx MBC Mode, 0x8018:SetAlgorithmParm, 0x0000:Off
	0x80, 0X17, 0x00, 0X31, 0x80, 0X18, 0x00, 0X00, //; 0x8017:SetAlgorithmParmID, 0x0031:Rx MBC Mode, 0x8018:SetAlgorithmParm, 0x0000:Off
	0x80, 0X17, 0x00, 0X1A, 0x80, 0X18, 0x00, 0X00, //; 0x8017:SetAlgorithmParmID, 0x001A:Use Tx ComfortNoise, 0x8018:SetAlgorithmParm, 0x0000:No
};

static const u8 incall_headphone_buf[] =
{
	0x80, 0x52, 0x00, 0x00, // disable digital pass through
	0x80, 0x26, 0x00, 0x01,	// select path route 0x0001
	0x80, 0X0C, 0x0A, 0X00, 0x80, 0X0D, 0x00, 0X0F, //; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x00: PCM WordLength0x800D: SetDeviceParm, 0x000F: 16 Bits
	0x80, 0X0C, 0x0A, 0X02, 0x80, 0X0D, 0x00, 0X00, //; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x02: PCM DelFromFsTx0x800D: SetDeviceParm, 0x0000: (0 clocks)
	0x80, 0X0C, 0x0A, 0X03, 0x80, 0X0D, 0x00, 0X01, //; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x03: PCM DelFromFsRx0x800D: SetDeviceParm, 0x0001: (1 clocks)
	0x80, 0X0C, 0x0A, 0X04, 0x80, 0X0D, 0x00, 0X02, //; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x04: PCM Latch Edge0x800D: SetDeviceParm, 0x0002:TxFalling/RxFalling
	0x80, 0X0C, 0x0A, 0X05, 0x80, 0X0D, 0x00, 0X01, //; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x05: PCM Endianness0x800D: SetDeviceParm, 0x0001:Big Endian
	0x80, 0X0C, 0x0A, 0X06, 0x80, 0X0D, 0x00, 0X00, //; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x06: PCM Tristate Enable0x800D: SetDeviceParm, 0x0000: Disable
	0x80, 0X0C, 0x0A, 0X07, 0x80, 0X0D, 0x00, 0X00, //; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x07: PCM Audio Port Mode0x800D: SetDeviceParm, 0x0000: PCM

	0x80, 0X0C, 0x0C, 0X00, 0x80, 0X0D, 0x00, 0X0F, //; 0x800C: SetDeviceParmID, 0x0C: PCM2, 0x00: PCM WordLength0x800D: SetDeviceParm, 0x000F: 16 Bits
	0x80, 0X0C, 0x0C, 0X02, 0x80, 0X0D, 0x00, 0X01, //; 0x800C: SetDeviceParmID, 0x0C: PCM2, 0x02: PCM DelFromFsTx0x800D: SetDeviceParm, 0x0001: (1 clocks)
	0x80, 0X0C, 0x0C, 0X03, 0x80, 0X0D, 0x00, 0X01, //; 0x800C: SetDeviceParmID, 0x0C: PCM2, 0x03: PCM DelFromFsRx0x800D: SetDeviceParm, 0x0001: (1 clocks)
	0x80, 0X0C, 0x0C, 0X04, 0x80, 0X0D, 0x00, 0X02, //; 0x800C: SetDeviceParmID, 0x0C: PCM2, 0x04: PCM Latch Edge0x800D: SetDeviceParm, 0x0002:TxFalling/RxFalling
	0x80, 0X0C, 0x0C, 0X05, 0x80, 0X0D, 0x00, 0X01, //; 0x800C: SetDeviceParmID, 0x0C: PCM2, 0x05: PCM Endianness0x800D: SetDeviceParm, 0x0001:Big Endian
	0x80, 0X0C, 0x0C, 0X06, 0x80, 0X0D, 0x00, 0X00, //; 0x800C: SetDeviceParmID, 0x0C: PCM2, 0x06: PCM Tristate Enable0x800D: SetDeviceParm, 0x0000: Disable
	0x80, 0X0C, 0x0C, 0X07, 0x80, 0X0D, 0x00, 0X00, //; 0x800C: SetDeviceParmID, 0x0C: PCM2, 0x07: PCM Audio Port Mode0x800D: SetDeviceParm, 0x0000: PCM

	0x80, 0X1C, 0x00, 0X01, // 0x801C: VoiceProcessing, 0x0001:On, 0x0000:Off
	0x80, 0X1B, 0x00, 0X04, // 0x801B:SetDigitalInputGain, 0x00:PCM-A left, 0x04:(4 dB)
	0x80, 0X1B, 0x01, 0X04, // 0x801B:SetDigitalInputGain, 0x00:PCM-A right, 0x04:(4 dB)
	0x80, 0X1B, 0x04, 0X12, // 0x801B:SetDigitalInputGain, 0x04:PCM-C left, 0x12:(18 dB)

	0x80, 0X17, 0x00, 0X15, 0x80, 0X18, 0x00, 0X00, //; 0x8017:SetAlgorithmParmID, 0x0015:Side Tone Mode, 0x8018:SetAlgorithmParm, 0x0000:Off
	0x80, 0X17, 0x00, 0X16, 0x80, 0X18, 0xFF, 0XEE, //; 0x8017:SetAlgorithmParmID, 0x0016:   Side Tone Gain (dB), 0x8018:SetAlgorithmParm, 0xFFEE:(-18 dB)
	0x80, 0X17, 0x00, 0X03, 0x80, 0X18, 0x00, 0X01, //; 0x8017:SetAlgorithmParmID, 0x0003:AEC Mode, 0x8018:SetAlgorithmParm, 0x0001:AEC On (auto select mode)
	0x80, 0X17, 0x00, 0X12, 0x80, 0X18, 0x00, 0X00, //; 0x8017:SetAlgorithmParmID, 0x0012:   Downlink Speaker Volume, 0x8018:SetAlgorithmParm, 0x0000:(0 dB)
	0x80, 0X17, 0x00, 0X23, 0x80, 0X18, 0x00, 0X00, //; 0x8017:SetAlgorithmParmID, 0x0023:   Use AEC Comfort Noise Fill, 0x8018:SetAlgorithmParm, 0x0000:No
	0x80, 0X17, 0x00, 0X34, 0x80, 0X18, 0x00, 0X00, //; 0x8017:SetAlgorithmParmID, 0x0034:   Echo Suppression Enhancement, 0x8018:SetAlgorithmParm, 0x0000:(0 dB)
	0x80, 0X17, 0x00, 0X2E, 0x80, 0X18, 0xFF, 0XC4, //; 0x8017:SetAlgorithmParmID, 0x002E:   AEC Comfort Noise Gain, 0x8018:SetAlgorithmParm, 0xFFC4:(-60 dB)
	0x80, 0X17, 0x01, 0X03, 0x80, 0X18, 0x00, 0X00, //; 0x8017:SetAlgorithmParmID, 0x0103:   DT ESE Back Off, 0x8018:SetAlgorithmParm, 0:(0 dB)
	0x80, 0X17, 0x00, 0X04, 0x80, 0X18, 0x00, 0X00, //; 0x8017:SetAlgorithmParmID, 0x0004:Use AGC, 0x8018:SetAlgorithmParm, 0x0000:No
	0x80, 0X17, 0x00, 0X28, 0x80, 0X18, 0x00, 0X00, //; 0x8017:SetAlgorithmParmID, 0x0028:Use Rx AGC, 0x8018:SetAlgorithmParm, 0x0000:No
	0x80, 0X17, 0x00, 0X29, 0x80, 0X18, 0xFF, 0XE6, //; 0x8017:SetAlgorithmParmID, 0x0029:   Rx AGC Target Level (dB), 0x8018:SetAlgorithmParm, 0xFFE6:(-26 dB)
	0x80, 0X17, 0x00, 0X2A, 0x80, 0X18, 0xFF, 0XA6, //; 0x8017:SetAlgorithmParmID, 0x002A:   Rx AGC Noise Floor (dB), 0x8018:SetAlgorithmParm, 0xFFA6:(-90 dB)
	0x80, 0X17, 0x00, 0X2B, 0x80, 0X18, 0x00, 0X04, //; 0x8017:SetAlgorithmParmID, 0x002B:   Rx AGC SNR Improve (dB), 0x8018:SetAlgorithmParm, 0x0004:(4 dB)
	0x80, 0X17, 0x00, 0X2C, 0x80, 0X18, 0x00, 0X04, //; 0x8017:SetAlgorithmParmID, 0x002C:   Rx AGC Up Rate (dBS), 0x8018:SetAlgorithmParm, 0x0004:(4 dBS)
	0x80, 0X17, 0x00, 0X2D, 0x80, 0X18, 0x00, 0X04, //; 0x8017:SetAlgorithmParmID, 0x002D:   Rx AGC Down Rate (dBS), 0x8018:SetAlgorithmParm, 0x0004:(4 dBS)
	0x80, 0X17, 0x01, 0X02, 0x80, 0X18, 0x00, 0X0F, //; 0x8017:SetAlgorithmParmID, 0x0102:   Rx AGC Max Gain (dB), 0x8018:SetAlgorithmParm, 0x000F:(15 dB)
	0x80, 0X17, 0x00, 0X3F, 0x80, 0X18, 0x00, 0X00, //; 0x8017:SetAlgorithmParmID, 0x003F:   Rx AGC Guard Band (dB), 0x8018:SetAlgorithmParm, 0x0000:(0 dB)
	0x80, 0X17, 0x00, 0X09, 0x80, 0X18, 0x00, 0X00, //; 0x8017:SetAlgorithmParmID, 0x0009:Speaker Enhancement Mode, 0x8018:SetAlgorithmParm, 0x0000:SE Off (HPF only)
	0x80, 0X17, 0x00, 0X0E, 0x80, 0X18, 0x00, 0X01, //; 0x8017:SetAlgorithmParmID, 0x000E:Far End Noise Suppression, 0x8018:SetAlgorithmParm, 0x0001:On (auto select mode)
	0x80, 0X17, 0x00, 0X4C, 0x80, 0X18, 0x00, 0X04, //; 0x8017:SetAlgorithmParmID, 0x004C:   Rx Noise Suppression Level, 0x8018:SetAlgorithmParm, 0x0004:Level 4
	0x80, 0X17, 0x00, 0X20, 0x80, 0X18, 0x00, 0X01, //; 0x8017:SetAlgorithmParmID, 0x0020:Tx PostEq Mode, 0x8018:SetAlgorithmParm, 0x0001:On
	0x80, 0X17, 0x00, 0X1F, 0x80, 0X18, 0x00, 0X01, //; 0x8017:SetAlgorithmParmID, 0x001F:Rx PostEq Mode, 0x8018:SetAlgorithmParm, 0x0001:On
	0x80, 0X17, 0x00, 0X30, 0x80, 0X18, 0x00, 0X00, //; 0x8017:SetAlgorithmParmID, 0x0030:Tx MBC Mode, 0x8018:SetAlgorithmParm, 0x0000:Off
	0x80, 0X17, 0x00, 0X31, 0x80, 0X18, 0x00, 0X00, //; 0x8017:SetAlgorithmParmID, 0x0031:Rx MBC Mode, 0x8018:SetAlgorithmParm, 0x0000:Off
	0x80, 0X17, 0x00, 0X1A, 0x80, 0X18, 0x00, 0X01, //; 0x8017:SetAlgorithmParmID, 0x001A:Use Tx ComfortNoise, 0x8018:SetAlgorithmParm, 0x0001:Yes
	0x80, 0X17, 0x00, 0X1B, 0x80, 0X18, 0xFF, 0XB5, //; 0x8017:SetAlgorithmParmID, 0x001B:   Tx ComfortNoise gain (dB), 0x8018:SetAlgorithmParm, 0xFFB5:(-75 dB)
	0x80, 0X17, 0x00, 0X1E, 0x80, 0X18, 0x00, 0X01, //; 0x8017:SetAlgorithmParmID, 0x001E:PST, 0x8018:SetAlgorithmParm, 0x0001:1
};

static const u8 incall_bt_buf[] =
{
	0x80, 0x52, 0x00, 0x00, // disable digital pass through
	0x80, 0x26, 0x00, 0x95, // select path route 0x0095
	0x80, 0x0C, 0x0D, 0x00, 0x80, 0x0D, 0x00, 0x0F, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x00: PCM WordLength0x800D: SetDeviceParm, 0x000F: 16 Bits
	0x80, 0x0C, 0x0D, 0x02, 0x80, 0x0D, 0x00, 0x00, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x02: PCM DelFromFsTx0x800D: SetDeviceParm, 0x0000: (0 clocks)
	0x80, 0x0C, 0x0D, 0x03, 0x80, 0x0D, 0x00, 0x01, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x03: PCM DelFromFsRx0x800D: SetDeviceParm, 0x0001: (1 clocks)
	0x80, 0x0C, 0x0D, 0x04, 0x80, 0x0D, 0x00, 0x01, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x04: PCM Latch Edge0x800D: SetDeviceParm, 0x0001:TxRising / RxRising
	0x80, 0x0C, 0x0D, 0x05, 0x80, 0x0D, 0x00, 0x01, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x05: PCM Endianness0x800D: SetDeviceParm, 0x0001:Big Endian
	0x80, 0x0C, 0x0D, 0x06, 0x80, 0x0D, 0x00, 0x00, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x06: PCM Tristate Enable0x800D: SetDeviceParm, 0x0000: Disable
	0x80, 0x0C, 0x0D, 0x07, 0x80, 0x0D, 0x00, 0x00, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x07: PCM Audio Port Mode0x800D: SetDeviceParm, 0x0000: PCM

	0x80, 0x0C, 0x0C, 0x00, 0x80, 0x0D, 0x00, 0x0F, // ; 0x800C: SetDeviceParmID, 0x0C: PCM2, 0x00: PCM WordLength0x800D: SetDeviceParm, 0x000F: 16 Bits
	0x80, 0x0C, 0x0C, 0x02, 0x80, 0x0D, 0x00, 0x01, // ; 0x800C: SetDeviceParmID, 0x0C: PCM2, 0x02: PCM DelFromFsTx0x800D: SetDeviceParm, 0x0001: (1 clocks)
	0x80, 0x0C, 0x0C, 0x03, 0x80, 0x0D, 0x00, 0x01, // ; 0x800C: SetDeviceParmID, 0x0C: PCM2, 0x03: PCM DelFromFsRx0x800D: SetDeviceParm, 0x0001: (1 clocks)
	0x80, 0x0C, 0x0C, 0x04, 0x80, 0x0D, 0x00, 0x02, // ; 0x800C: SetDeviceParmID, 0x0C: PCM2, 0x04: PCM Latch Edge0x800D: SetDeviceParm, 0x0002:TxFalling/RxFalling
	0x80, 0x0C, 0x0C, 0x05, 0x80, 0x0D, 0x00, 0x01, // ; 0x800C: SetDeviceParmID, 0x0C: PCM2, 0x05: PCM Endianness0x800D: SetDeviceParm, 0x0001:Big Endian
	0x80, 0x0C, 0x0C, 0x06, 0x80, 0x0D, 0x00, 0x00, // ; 0x800C: SetDeviceParmID, 0x0C: PCM2, 0x06: PCM Tristate Enable0x800D: SetDeviceParm, 0x0000: Disable
	0x80, 0x0C, 0x0C, 0x07, 0x80, 0x0D, 0x00, 0x00, // ; 0x800C: SetDeviceParmID, 0x0C: PCM2, 0x07: PCM Audio Port Mode0x800D: SetDeviceParm, 0x0000: PCM
};

static const u8 incall_bt_vpoff_buf[] =
{
	0x80, 0x52, 0x00, 0x00, // disable digital pass through
	0x80, 0x26, 0x00, 0x95, // select path route 0x0095
	0x80, 0x0C, 0x0D, 0x00, 0x80, 0x0D, 0x00, 0x0F, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x00: PCM WordLength0x800D: SetDeviceParm, 0x000F: 16 Bits
	0x80, 0x0C, 0x0D, 0x02, 0x80, 0x0D, 0x00, 0x00, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x02: PCM DelFromFsTx0x800D: SetDeviceParm, 0x0000: (0 clocks)
	0x80, 0x0C, 0x0D, 0x03, 0x80, 0x0D, 0x00, 0x01, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x03: PCM DelFromFsRx0x800D: SetDeviceParm, 0x0001: (1 clocks)
	0x80, 0x0C, 0x0D, 0x04, 0x80, 0x0D, 0x00, 0x01, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x04: PCM Latch Edge0x800D: SetDeviceParm, 0x0001:TxRising / RxRising
	0x80, 0x0C, 0x0D, 0x05, 0x80, 0x0D, 0x00, 0x01, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x05: PCM Endianness0x800D: SetDeviceParm, 0x0001:Big Endian
	0x80, 0x0C, 0x0D, 0x06, 0x80, 0x0D, 0x00, 0x00, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x06: PCM Tristate Enable0x800D: SetDeviceParm, 0x0000: Disable
	0x80, 0x0C, 0x0D, 0x07, 0x80, 0x0D, 0x00, 0x00, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x07: PCM Audio Port Mode0x800D: SetDeviceParm, 0x0000: PCM

	0x80, 0x0C, 0x0C, 0x00, 0x80, 0x0D, 0x00, 0x0F, // ; 0x800C: SetDeviceParmID, 0x0C: PCM2, 0x00: PCM WordLength0x800D: SetDeviceParm, 0x000F: 16 Bits
	0x80, 0x0C, 0x0C, 0x02, 0x80, 0x0D, 0x00, 0x01, // ; 0x800C: SetDeviceParmID, 0x0C: PCM2, 0x02: PCM DelFromFsTx0x800D: SetDeviceParm, 0x0001: (1 clocks)
	0x80, 0x0C, 0x0C, 0x03, 0x80, 0x0D, 0x00, 0x01, // ; 0x800C: SetDeviceParmID, 0x0C: PCM2, 0x03: PCM DelFromFsRx0x800D: SetDeviceParm, 0x0001: (1 clocks)
	0x80, 0x0C, 0x0C, 0x04, 0x80, 0x0D, 0x00, 0x02, // ; 0x800C: SetDeviceParmID, 0x0C: PCM2, 0x04: PCM Latch Edge0x800D: SetDeviceParm, 0x0002:TxFalling/RxFalling
	0x80, 0x0C, 0x0C, 0x05, 0x80, 0x0D, 0x00, 0x01, // ; 0x800C: SetDeviceParmID, 0x0C: PCM2, 0x05: PCM Endianness0x800D: SetDeviceParm, 0x0001:Big Endian
	0x80, 0x0C, 0x0C, 0x06, 0x80, 0x0D, 0x00, 0x00, // ; 0x800C: SetDeviceParmID, 0x0C: PCM2, 0x06: PCM Tristate Enable0x800D: SetDeviceParm, 0x0000: Disable
	0x80, 0x0C, 0x0C, 0x07, 0x80, 0x0D, 0x00, 0x00, // ; 0x800C: SetDeviceParmID, 0x0C: PCM2, 0x07: PCM Audio Port Mode0x800D: SetDeviceParm, 0x0000: PCM
};

static const u8 voip_receiver_buf[] =
{
	0x80, 0x52, 0x00, 0x00, // disable digital pass through
	0x80, 0x26, 0x00, 0x93, // select path route 0x0093
	0x80, 0x0C, 0x0A, 0x00, 0x80, 0x0D, 0x00, 0x0F, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x00: PCM WordLength0x800D: SetDeviceParm, 0x000F: 16 Bits
	0x80, 0x0C, 0x0A, 0x02, 0x80, 0x0D, 0x00, 0x00, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x02: PCM DelFromFsTx0x800D: SetDeviceParm, 0x0000: (0 clocks)
	0x80, 0x0C, 0x0A, 0x03, 0x80, 0x0D, 0x00, 0x01, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x03: PCM DelFromFsRx0x800D: SetDeviceParm, 0x0001: (1 clocks)
	0x80, 0x0C, 0x0A, 0x04, 0x80, 0x0D, 0x00, 0x02, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x04: PCM Latch Edge0x800D: SetDeviceParm, 0x0002:TxFalling/RxFalling
	0x80, 0x0C, 0x0A, 0x05, 0x80, 0x0D, 0x00, 0x01, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x05: PCM Endianness0x800D: SetDeviceParm, 0x0001:Big Endian
	0x80, 0x0C, 0x0A, 0x06, 0x80, 0x0D, 0x00, 0x00, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x06: PCM Tristate Enable0x800D: SetDeviceParm, 0x0000: Disable
	0x80, 0x0C, 0x0A, 0x07, 0x80, 0x0D, 0x00, 0x00, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x07: PCM Audio Port Mode0x800D: SetDeviceParm, 0x0000: PCM

	0x80, 0x0C, 0x0B, 0x00, 0x80, 0x0D, 0x00, 0x0F, // ; 0x800C: SetDeviceParmID, 0x0B: PCM2, 0x00: PCM WordLength0x800D: SetDeviceParm, 0x000F: 16 Bits
	0x80, 0x0C, 0x0B, 0x02, 0x80, 0x0D, 0x00, 0x01, // ; 0x800C: SetDeviceParmID, 0x0B: PCM2, 0x02: PCM DelFromFsTx0x800D: SetDeviceParm, 0x0001: (1 clocks)
	0x80, 0x0C, 0x0B, 0x03, 0x80, 0x0D, 0x00, 0x01, // ; 0x800C: SetDeviceParmID, 0x0B: PCM2, 0x03: PCM DelFromFsRx0x800D: SetDeviceParm, 0x0001: (1 clocks)
	0x80, 0x0C, 0x0B, 0x04, 0x80, 0x0D, 0x00, 0x02, // ; 0x800C: SetDeviceParmID, 0x0B: PCM2, 0x04: PCM Latch Edge0x800D: SetDeviceParm, 0x0002:TxFalling/RxFalling
	0x80, 0x0C, 0x0B, 0x05, 0x80, 0x0D, 0x00, 0x01, // ; 0x800C: SetDeviceParmID, 0x0B: PCM2, 0x05: PCM Endianness0x800D: SetDeviceParm, 0x0001:Big Endian
	0x80, 0x0C, 0x0B, 0x06, 0x80, 0x0D, 0x00, 0x00, // ; 0x800C: SetDeviceParmID, 0x0B: PCM2, 0x06: PCM Tristate Enable0x800D: SetDeviceParm, 0x0000: Disable
	0x80, 0x0C, 0x0B, 0x07, 0x80, 0x0D, 0x00, 0x00, // ; 0x800C: SetDeviceParmID, 0x0B: PCM2, 0x07: PCM Audio Port Mode0x800D: SetDeviceParm, 0x0000: PCM
};

static const u8 voip_speaker_buf[] =
{
	0x80, 0x52, 0x00, 0x00, // disable digital pass through
	0x80, 0x26, 0x00, 0x93, // select path route 0x0093
	0x80, 0x0C, 0x0A, 0x00, 0x80, 0x0D, 0x00, 0x0F, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x00: PCM WordLength0x800D: SetDeviceParm, 0x000F: 16 Bits
	0x80, 0x0C, 0x0A, 0x02, 0x80, 0x0D, 0x00, 0x00, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x02: PCM DelFromFsTx0x800D: SetDeviceParm, 0x0000: (0 clocks)
	0x80, 0x0C, 0x0A, 0x03, 0x80, 0x0D, 0x00, 0x01, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x03: PCM DelFromFsRx0x800D: SetDeviceParm, 0x0001: (1 clocks)
	0x80, 0x0C, 0x0A, 0x04, 0x80, 0x0D, 0x00, 0x02, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x04: PCM Latch Edge0x800D: SetDeviceParm, 0x0002:TxFalling/RxFalling
	0x80, 0x0C, 0x0A, 0x05, 0x80, 0x0D, 0x00, 0x01, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x05: PCM Endianness0x800D: SetDeviceParm, 0x0001:Big Endian
	0x80, 0x0C, 0x0A, 0x06, 0x80, 0x0D, 0x00, 0x00, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x06: PCM Tristate Enable0x800D: SetDeviceParm, 0x0000: Disable
	0x80, 0x0C, 0x0A, 0x07, 0x80, 0x0D, 0x00, 0x00, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x07: PCM Audio Port Mode0x800D: SetDeviceParm, 0x0000: PCM

	0x80, 0x0C, 0x0B, 0x00, 0x80, 0x0D, 0x00, 0x0F, // ; 0x800C: SetDeviceParmID, 0x0B: PCM2, 0x00: PCM WordLength0x800D: SetDeviceParm, 0x000F: 16 Bits
	0x80, 0x0C, 0x0B, 0x02, 0x80, 0x0D, 0x00, 0x01, // ; 0x800C: SetDeviceParmID, 0x0B: PCM2, 0x02: PCM DelFromFsTx0x800D: SetDeviceParm, 0x0001: (1 clocks)
	0x80, 0x0C, 0x0B, 0x03, 0x80, 0x0D, 0x00, 0x01, // ; 0x800C: SetDeviceParmID, 0x0B: PCM2, 0x03: PCM DelFromFsRx0x800D: SetDeviceParm, 0x0001: (1 clocks)
	0x80, 0x0C, 0x0B, 0x04, 0x80, 0x0D, 0x00, 0x02, // ; 0x800C: SetDeviceParmID, 0x0B: PCM2, 0x04: PCM Latch Edge0x800D: SetDeviceParm, 0x0002:TxFalling/RxFalling
	0x80, 0x0C, 0x0B, 0x05, 0x80, 0x0D, 0x00, 0x01, // ; 0x800C: SetDeviceParmID, 0x0B: PCM2, 0x05: PCM Endianness0x800D: SetDeviceParm, 0x0001:Big Endian
	0x80, 0x0C, 0x0B, 0x06, 0x80, 0x0D, 0x00, 0x00, // ; 0x800C: SetDeviceParmID, 0x0B: PCM2, 0x06: PCM Tristate Enable0x800D: SetDeviceParm, 0x0000: Disable
	0x80, 0x0C, 0x0B, 0x07, 0x80, 0x0D, 0x00, 0x00, // ; 0x800C: SetDeviceParmID, 0x0B: PCM2, 0x07: PCM Audio Port Mode0x800D: SetDeviceParm, 0x0000: PCM
};

static const u8 voip_headphone_buf[] =
{
	0x80, 0x52, 0x00, 0x00, // disable digital pass through
	0x80, 0x26, 0x00, 0x93, // select path route 0x0093
	0x80, 0x0C, 0x0A, 0x00, 0x80, 0x0D, 0x00, 0x0F, // ; 0x800C: SetDeviceParmID, 0x0A: PCM1, 0x00: PCM WordLength0x800D: SetDeviceParm, 0x000F: 16 Bits
	0x80, 0x0C, 0x0A, 0x02, 0x80, 0x0D, 0x00, 0x00, // ; 0x800C: SetDeviceParmID, 0x0A: PCM1, 0x02: PCM DelFromFsTx0x800D: SetDeviceParm, 0x0000: (0 clocks)
	0x80, 0x0C, 0x0A, 0x03, 0x80, 0x0D, 0x00, 0x01, // ; 0x800C: SetDeviceParmID, 0x0A: PCM1, 0x03: PCM DelFromFsRx0x800D: SetDeviceParm, 0x0001: (1 clocks)
	0x80, 0x0C, 0x0A, 0x04, 0x80, 0x0D, 0x00, 0x02, // ; 0x800C: SetDeviceParmID, 0x0A: PCM1, 0x04: PCM Latch Edge0x800D: SetDeviceParm, 0x0002:TxFalling/RxFalling
	0x80, 0x0C, 0x0A, 0x05, 0x80, 0x0D, 0x00, 0x01, // ; 0x800C: SetDeviceParmID, 0x0A: PCM1, 0x05: PCM Endianness0x800D: SetDeviceParm, 0x0001:Big Endian
	0x80, 0x0C, 0x0A, 0x06, 0x80, 0x0D, 0x00, 0x00, // ; 0x800C: SetDeviceParmID, 0x0A: PCM1, 0x06: PCM Tristate Enable0x800D: SetDeviceParm, 0x0000: Disable
	0x80, 0x0C, 0x0A, 0x07, 0x80, 0x0D, 0x00, 0x00, // ; 0x800C: SetDeviceParmID, 0x0A: PCM1, 0x07: PCM Audio Port Mode0x800D: SetDeviceParm, 0x0000: PCM

	0x80, 0x0C, 0x0B, 0x00, 0x80, 0x0D, 0x00, 0x0F, // ; 0x800C: SetDeviceParmID, 0x0B: PCM2, 0x00: PCM WordLength0x800D: SetDeviceParm, 0x000F: 16 Bits
	0x80, 0x0C, 0x0B, 0x02, 0x80, 0x0D, 0x00, 0x01, // ; 0x800C: SetDeviceParmID, 0x0B: PCM2, 0x02: PCM DelFromFsTx0x800D: SetDeviceParm, 0x0001: (1 clocks)
	0x80, 0x0C, 0x0B, 0x03, 0x80, 0x0D, 0x00, 0x01, // ; 0x800C: SetDeviceParmID, 0x0B: PCM2, 0x03: PCM DelFromFsRx0x800D: SetDeviceParm, 0x0001: (1 clocks)
	0x80, 0x0C, 0x0B, 0x04, 0x80, 0x0D, 0x00, 0x02, // ; 0x800C: SetDeviceParmID, 0x0B: PCM2, 0x04: PCM Latch Edge0x800D: SetDeviceParm, 0x0002:TxFalling/RxFalling
	0x80, 0x0C, 0x0B, 0x05, 0x80, 0x0D, 0x00, 0x01, // ; 0x800C: SetDeviceParmID, 0x0B: PCM2, 0x05: PCM Endianness0x800D: SetDeviceParm, 0x0001:Big Endian
	0x80, 0x0C, 0x0B, 0x06, 0x80, 0x0D, 0x00, 0x00, // ; 0x800C: SetDeviceParmID, 0x0B: PCM2, 0x06: PCM Tristate Enable0x800D: SetDeviceParm, 0x0000: Disable
	0x80, 0x0C, 0x0B, 0x07, 0x80, 0x0D, 0x00, 0x00, // ; 0x800C: SetDeviceParmID, 0x0B: PCM2, 0x07: PCM Audio Port Mode0x800D: SetDeviceParm, 0x0000: PCM
};

static const u8 voip_bt_buf[] =
{
	0x80, 0x52, 0x00, 0x00, // disable digital pass through
	0x80, 0x26, 0x00, 0x96, // select path route 0x0096
	0x80, 0x0C, 0x0D, 0x00, 0x80, 0x0D, 0x00, 0x0F, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x00: PCM WordLength0x800D: SetDeviceParm, 0x000F: 16 Bits
	0x80, 0x0C, 0x0D, 0x02, 0x80, 0x0D, 0x00, 0x00, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x02: PCM DelFromFsTx0x800D: SetDeviceParm, 0x0000: (0 clocks)
	0x80, 0x0C, 0x0D, 0x03, 0x80, 0x0D, 0x00, 0x01, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x03: PCM DelFromFsRx0x800D: SetDeviceParm, 0x0001: (1 clocks)
	0x80, 0x0C, 0x0D, 0x04, 0x80, 0x0D, 0x00, 0x01, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x04: PCM Latch Edge0x800D: SetDeviceParm, 0x0001:TxRising / RxRising
	0x80, 0x0C, 0x0D, 0x05, 0x80, 0x0D, 0x00, 0x01, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x05: PCM Endianness0x800D: SetDeviceParm, 0x0001:Big Endian
	0x80, 0x0C, 0x0D, 0x06, 0x80, 0x0D, 0x00, 0x00, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x06: PCM Tristate Enable0x800D: SetDeviceParm, 0x0000: Disable
	0x80, 0x0C, 0x0D, 0x07, 0x80, 0x0D, 0x00, 0x00, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x07: PCM Audio Port Mode0x800D: SetDeviceParm, 0x0000: PCM

	0x80, 0x0C, 0x0B, 0x00, 0x80, 0x0D, 0x00, 0x0F, // ; 0x800C: SetDeviceParmID, 0x0B: PCM2, 0x00: PCM WordLength0x800D: SetDeviceParm, 0x000F: 16 Bits
	0x80, 0x0C, 0x0B, 0x02, 0x80, 0x0D, 0x00, 0x01, // ; 0x800C: SetDeviceParmID, 0x0B: PCM2, 0x02: PCM DelFromFsTx0x800D: SetDeviceParm, 0x0001: (1 clocks)
	0x80, 0x0C, 0x0B, 0x03, 0x80, 0x0D, 0x00, 0x01, // ; 0x800C: SetDeviceParmID, 0x0B: PCM2, 0x03: PCM DelFromFsRx0x800D: SetDeviceParm, 0x0001: (1 clocks)
	0x80, 0x0C, 0x0B, 0x04, 0x80, 0x0D, 0x00, 0x02, // ; 0x800C: SetDeviceParmID, 0x0B: PCM2, 0x04: PCM Latch Edge0x800D: SetDeviceParm, 0x0002:TxFalling/RxFalling
	0x80, 0x0C, 0x0B, 0x05, 0x80, 0x0D, 0x00, 0x01, // ; 0x800C: SetDeviceParmID, 0x0B: PCM2, 0x05: PCM Endianness0x800D: SetDeviceParm, 0x0001:Big Endian
	0x80, 0x0C, 0x0B, 0x06, 0x80, 0x0D, 0x00, 0x00, // ; 0x800C: SetDeviceParmID, 0x0B: PCM2, 0x06: PCM Tristate Enable0x800D: SetDeviceParm, 0x0000: Disable
	0x80, 0x0C, 0x0B, 0x07, 0x80, 0x0D, 0x00, 0x00, // ; 0x800C: SetDeviceParmID, 0x0B: PCM2, 0x07: PCM Audio Port Mode0x800D: SetDeviceParm, 0x0000: PCM
	//
};


static const u8 voip_bt_vpoff_buf[] =
{
	0x80, 0x52, 0x00, 0x00, // disable digital pass through
	0x80, 0x26, 0x00, 0x96, // select path route 0x0096
	0x80, 0x0C, 0x0D, 0x00, 0x80, 0x0D, 0x00, 0x0F, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x00: PCM WordLength0x800D: SetDeviceParm, 0x000F: 16 Bits
	0x80, 0x0C, 0x0D, 0x02, 0x80, 0x0D, 0x00, 0x00, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x02: PCM DelFromFsTx0x800D: SetDeviceParm, 0x0000: (0 clocks)
	0x80, 0x0C, 0x0D, 0x03, 0x80, 0x0D, 0x00, 0x01, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x03: PCM DelFromFsRx0x800D: SetDeviceParm, 0x0001: (1 clocks)
	0x80, 0x0C, 0x0D, 0x04, 0x80, 0x0D, 0x00, 0x01, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x04: PCM Latch Edge0x800D: SetDeviceParm, 0x0001:TxRising / RxRising
	0x80, 0x0C, 0x0D, 0x05, 0x80, 0x0D, 0x00, 0x01, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x05: PCM Endianness0x800D: SetDeviceParm, 0x0001:Big Endian
	0x80, 0x0C, 0x0D, 0x06, 0x80, 0x0D, 0x00, 0x00, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x06: PCM Tristate Enable0x800D: SetDeviceParm, 0x0000: Disable
	0x80, 0x0C, 0x0D, 0x07, 0x80, 0x0D, 0x00, 0x00, // ; 0x800C: SetDeviceParmID, 0x0B: PCM1, 0x07: PCM Audio Port Mode0x800D: SetDeviceParm, 0x0000: PCM

	0x80, 0x0C, 0x0B, 0x00, 0x80, 0x0D, 0x00, 0x0F, // ; 0x800C: SetDeviceParmID, 0x0B: PCM2, 0x00: PCM WordLength0x800D: SetDeviceParm, 0x000F: 16 Bits
	0x80, 0x0C, 0x0B, 0x02, 0x80, 0x0D, 0x00, 0x01, // ; 0x800C: SetDeviceParmID, 0x0B: PCM2, 0x02: PCM DelFromFsTx0x800D: SetDeviceParm, 0x0001: (1 clocks)
	0x80, 0x0C, 0x0B, 0x03, 0x80, 0x0D, 0x00, 0x01, // ; 0x800C: SetDeviceParmID, 0x0B: PCM2, 0x03: PCM DelFromFsRx0x800D: SetDeviceParm, 0x0001: (1 clocks)
	0x80, 0x0C, 0x0B, 0x04, 0x80, 0x0D, 0x00, 0x02, // ; 0x800C: SetDeviceParmID, 0x0B: PCM2, 0x04: PCM Latch Edge0x800D: SetDeviceParm, 0x0002:TxFalling/RxFalling
	0x80, 0x0C, 0x0B, 0x05, 0x80, 0x0D, 0x00, 0x01, // ; 0x800C: SetDeviceParmID, 0x0B: PCM2, 0x05: PCM Endianness0x800D: SetDeviceParm, 0x0001:Big Endian
	0x80, 0x0C, 0x0B, 0x06, 0x80, 0x0D, 0x00, 0x00, // ; 0x800C: SetDeviceParmID, 0x0B: PCM2, 0x06: PCM Tristate Enable0x800D: SetDeviceParm, 0x0000: Disable
	0x80, 0x0C, 0x0B, 0x07, 0x80, 0x0D, 0x00, 0x00, // ; 0x800C: SetDeviceParmID, 0x0B: PCM2, 0x07: PCM Audio Port Mode0x800D: SetDeviceParm, 0x0000: PCM
};

static const u8 bt_ring_buf[] = {
	0x80, 0x52, 0x00, 0xF3,
};

#endif /* __LINUX_ES305B_PARAM_H_ */
