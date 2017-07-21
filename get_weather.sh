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
	# echo $(date)" | "$*
	echo $*
} 

function show_help() {
# Show the help documentation
	log_message ""
	log_message "Usage:"
	log_message "get_weather.sh <param>"
	log_message ""
	log_message "Param can be replaced with one of the following:"
	log_message "configfile - The full path of the configuration file."
	log_message "help - Show the help information about this script."
	log_message ""
	log_message "For more information, visit https://github.com/bitsecondal/farmosnws"
}
 
## SCRIPT MAIN ## SCRIPT MAIN ## SCRIPT MAIN ##
## SCRIPT MAIN ## SCRIPT MAIN ## SCRIPT MAIN ##

FILENAME="${1}"

# verify that the configuration file exists
if [[ -f ${FILENAME} ]]; then

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
	show_help
fi

