/** @file	WiimoteTracker.h
	@brief	header

	@date	2010

	@author
	Ryan Pavlik
	<rpavlik@iastate.edu> and <abiryan@ryand.net>
	http://academic.cleardefinition.com/
	Iowa State University Virtual Reality Applications Center
	Human-Computer Interaction Graduate Program
*/

#pragma once
#ifndef _WIIMOTETRACKER_H
#define _WIIMOTETRACKER_H

// Internal Includes
// - none

// Library/third-party includes
// - none

// Standard includes
#include <string>

const float PROGRESS_EVENT_TIMEOUT = 0.2;
const float PROGRESS_WINDOW_TIMEOUT = 3.0;

class WiimoteTrackerGUI;
class WiimoteTrackerConfigGUI;
class StartupProgress;
class vrpn_Connection;
class vrpn_WiiMote;
class vrpn_Tracker_WiimoteHead;

class WiimoteTracker {
	public:
		WiimoteTracker();
		~WiimoteTracker();

		enum Component {
			CMP_CONNECTION,
			CMP_WIIMOTE,
			CMP_TRACKER,
			CMP_CLIENT
		};

		/// @name GUI-related methods
		/// @{
		void setLEDDistance(const float distanceInMeters);
		void setTrackerName(const std::string & trackerName);

		void run();
		void reconfigure();
		void stopTrackerSystem();
		void startTrackerSystem();

		void setProgress(const Component cmp, const float completion, const char * message);

		void systemIsDown();
		void systemIsUp();
		/// @}

		/// @name VRPN-related methods
		/// @{
		bool startConnection();
		void teardownConnection();

		bool startWiimoteDevice();
		void teardownWiimoteDevice();

		bool startTrackerDevice();
		void teardownTrackerDevice();

		bool startClientDevice();
		void teardownClientDevice();
		/// @}

		bool isSystemRunning(bool updateProgress = false);




	protected:
		/// @name Configuration data
		/// @{
		std::string _trackerName;
		float _ledDistance;
		/// @}

		/// @name VRPN objects
		/// @{
		vrpn_Connection * _connection;
		vrpn_WiiMote * _wiimote;
		vrpn_Tracker_WiimoteHead * _tracker;
		/// @}

		/// @name GUI windows
		/// @{
		StartupProgress * _progress;
		WiimoteTrackerConfigGUI * _config;
		WiimoteTrackerGUI * _gui;
		/// @}


};
#endif // WIIMOTETRACKER
