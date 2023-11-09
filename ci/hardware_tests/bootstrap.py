import os
import sys

from device.legacy import TrezorOne
from device.core import TrezorCore


def main(model: str, file: str = None):
    t1 = TrezorOne(
        os.getenv("T1_UHUB_LOCATION"),
        os.getenv("T1_ARDUINO_SERIAL"),
        os.getenv("T1_UHUB_PORT"),
    )
    tt = TrezorCore(os.getenv("TT_UHUB_LOCATION"), os.getenv("TT_UHUB_PORT"))

    if model == "t1":
        tt.power_off()
        path = t1.update_firmware(file)
    elif model == "tt":
        t1.power_off()
        path = tt.update_firmware(file, "Trezor T")
    elif model == "t2b1":
        path = tt.update_firmware(file, "Safe 3")
    else:
        raise ValueError("Unknown Trezor model.")

    print(path)


if __name__ == "__main__":
    model = sys.argv[1]
    if len(sys.argv) == 3:
        main(model, file=sys.argv[2])
    else:
        main(model)
