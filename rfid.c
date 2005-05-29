
#include <stdio.h>
#include <string.h>

#include <rfid/rfid_reader_cm5121.h>
#include <rfid/rfid_protocol.h>
#include <rfid/rfid_protocol_tcl.h>

const char *
rfid_hexdump(const void *data, unsigned int len)
{
	static char string[1024];
	unsigned char *d = (unsigned char *) data;
	unsigned int i, left;

	string[0] = '\0';
	left = sizeof(string);
	for (i = 0; len--; i += 3) {
		if (i >= sizeof(string) -4)
			break;
		snprintf(string+i, 4, " %02x", *d++);
	}
	return string;
}

int rfid_init()
{
	rfid_reader_register(&rfid_reader_cm5121);
	rfid_layer2_register(&rfid_layer2_iso14443a);
	rfid_layer2_register(&rfid_layer2_iso14443b);
	rfid_protocol_register(&rfid_protocol_tcl);

	return 0;
}

void rfid_fini()
{
	/* FIXME: implementation */
}
