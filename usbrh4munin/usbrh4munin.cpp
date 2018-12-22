// usbrh4munin.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <comutil.h>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>

#include "usbrh.h"

#pragma comment(lib,"USBMeter.lib")

HRESULT GetDevices(CSimpleArray<BSTR> &devices) {
	int index = 0;
	while (1) {
		CComBSTR name = FindUSB(&index);
		if (name.Length() == 0) {
			break;
		}
		devices.Add(name);
	}
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	_setmode(_fileno(stdout), _O_BINARY);

	CSimpleArray<BSTR> devices;
	GetDevices(devices);

	if (devices.GetSize() == 0) {
		_tperror(_T("NO DEVICE"));
	}


	#define LF _T("\x0A")

	for (int j=0; j<argc; j++) {
		if (_tcscmp(argv[j], _T("name")) == 0) {
			_tprintf(_T("usbtemp"));
		}
		if (_tcscmp(argv[j], _T("config")) == 0) {
			_tprintf(
				_T("graph_title Temprature and humidity") LF
				_T("graph_category sensors") LF
				_T("graph_args --base 1000 -l 0") LF
				_T("graph_vlabel Temprature and humidity") LF
				_T("graph_info usbrh4munin") LF
				);

			for (int k=0; k<devices.GetSize(); k++) {
				_tprintf(_T("usb%dtemp.label usb%d temprature") LF, k, k);
				_tprintf(_T("usb%dhumid.label usb%d humidity") LF, k, k);
			}
			_tprintf(
				_T(".") LF
				);
		}
	}

	if (argc == 1) {
		for (int k=0; k<devices.GetSize(); k++) {
			double		temp = 0;
			double		humid = 0;
			int result = GetTempHumidTrue(devices[k],  &temp, &humid);

			if (result == 0) {
				_tprintf(_T("usb%dtemp.value %f") LF, k, temp);
				_tprintf(_T("usb%dhumid.value %f") LF, k, humid);
			}
			else {
				_tprintf(_T("usb%dtemp.value ERROR") LF, k);
				_tprintf(_T("usb%dhumid.value ERROR") LF, k);
			}
		}
		_tprintf(_T(".") LF);
		//_tprintf();
	}

	return 0;
}

