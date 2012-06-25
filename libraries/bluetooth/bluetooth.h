/*
 *  Bluetooth.h - Library for controlling
 *  the seeeduino bluetooth shield.
 *  (cc) 2012 Gerardo Puerta <gerardo>at<gnuardo.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  
 *  02110-1301  USA
 *
 */

#include "Arduino.h"

#ifndef Bluetooth_h
#define Bluetooth_h

#include <SoftwareSerial.h>


// Start String
#define SS \r\n
// End String
#define ES \r\n

// Working Mode
#define WM +STWMOD=
// Name
#define SN +STNA=
// Pin code
#define PN +STPIN=
// AutoConnect
#define AC +STAUTO=
// Permit Connection
#define PC +STOAUT=
// Connect to device
#define CD +CONN=
// Inquire
#define IN +INQ=
// Autoreconnect
#define AR +LOSSRECONN=
// Input Pin Code
#define IP +RTPIN=



class Bluetooth
{

 public:
  /*
  Put pinModes and inits serial communication
  with the BT module
  */
  Bluetooth(int RX, int TX, int BaudRate);

  /*
  Set working mode:
  False: slave.
  True: master.
  */
  void setWorkingMode(bool mode);
  bool getWorkingMode();
  
  //void setBaudRate(int br);

  void setName(String name);
  String getName();

  void setAutoConnect(bool activate);
  bool getAutoConnect();

  void setPermitConnect(bool activate);
  bool getPermitConnect();

  void setPinCode(int pin);
  int  getPinCode();

  void connectToDevice(String address);
  void inquire(bool activate);
  // Autoreconnecting when master is beyond range
  void setAutoReconnect(bool activate);
  void inputPinCode(int pin);

  String readLocalAddress();
  String inquiry();
  String connectToDevice(String address);
  String status();

 private:
  int rx;
  int tx;
  int baudrate;
  SoftwareSerial *serial;
  String name;
  int pin;
  bool mode;
  bool autoconnect;
  bool permitconnect;
}

#endif

