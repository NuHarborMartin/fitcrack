#!/bin/bash

# Update server daemons
# This file is part of Fitcrack installer
# Author: Radek Hranicky (ihranicky@fit.vutbr.cz)

echo "                                                          "
echo "============ Fitcrack server daemons update =============="
echo "                                                          "

########################################
# Configure and build server
########################################
echo "You chose to update Fitcrack server Daemons."
echo "We recommend to first stop the ongoing cracking jobs."
echo " "
echo "This process will:"
echo " - Rebuild and update the following server daemons:"
echo "   * Generator"
echo "   * Assimilator"
echo "   * Validator"
echo "   * Trickler"
echo " "
echo "The database and project settings will be untouched."
echo "However, the project will have to be restarted."
read -e -p "Do you wish to continue? [y/N] (default: y): " BUILD_SERVER
BUILD_SERVER=${BUILD_SERVER:-y}

if [ $BUILD_SERVER = "y" ]; then
  # Stop server
  echo "Stopping Fitcrack server..."
  MYDIR=$(pwd)
  cd $BOINC_PROJECT_DIR
  sudo -u $BOINC_USER ./bin/stop
  cd $MYDIR
  echo "Server stopped."

  # Rebuild server
  source installer/build_server.sh

  # Reinstall daemons
  source installer/install_daemons.sh

  pkill -f pcfg_monitor.py
  pkill -f measure_usage.py

  echo "Starting Fitcrack server again..."
  MYDIR=$(pwd)
  cd $BOINC_PROJECT_DIR
  sudo -u $BOINC_USER ./bin/start
  sudo -u $BOINC_USER ./bin/status
  cd $MYDIR
  echo "Server daemons updated and started :-)"
fi

echo "All done."
