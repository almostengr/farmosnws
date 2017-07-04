#!/bin/bash

################################################################################
# Description: Load the weather data in XML format from the National Weather
# Service into a given location.
# 
# Usage: get_weather.sh <configfile>
# "<configfile>" is to be replaced with the full path of the configuration file.
# 
# Author: Kenny Robinson, Bit Second Tech
################################################################################

# log all of the status and error messages
function log_message() {
	echo $(date)" | "$*
} 
 
## SCRIPT MAIN 
## SCRIPT MAIN 

# verify that the configuration file exists
if [ -e $1 ]; then

	log_message "Loading the configuration"
	
	# load the configuration file
	source $1

	log_message "Done loading the configuration"

	log_message "Getting the weather data"

	# get and save the weather data
	/usr/bin/wget -O ${feedsdir}/${location}_$(/bin/date +%Y%m%d%H%M%S).xml http://w1.weather.gov/xml/current_obs/${location}.xml
	
	log_message "Done getting the weather data"
else
  log_message "Configuration file does not exist."
fi

