/*
 * Author : see AUTHORS
 * Licence: MIT, see LICENSE
 */

#ifdef _WIN32

#ifndef PROCESSWINDOWS_HPP 
#define PROCESSWINDOWS_HPP

#include <windows.h>

#include "PipeWindows.hpp"
#include "ProcessBase.hpp"

/** Class representing sub-process on Windows system */
class ProcessWindows : public ProcessBase {

    private:

	STARTUPINFO startup_info_;			/**< Windows STARTUPINFO structure */
	PROCESS_INFORMATION process_information_;	/**< Windows PROCESS_INFORMATION structure */
    protected:	

        /**
         * @brief   Contains steps leading to execution of executable with appropiate arguments.
         */
        void launchSubprocess();

        virtual char getQuoteChar() {return '"';}
    
    public:
      /**
       * @brief   Conctutor which sets name of the executable
       * @param   exec_name [in] Name of the executable
       * @param   exec_args [in] Arguments which to pass to executable
       * @param   is_external_generator [in] Whether executable is an external
       * password generator or not
       */
      ProcessWindows(const std::string &exec_name,
                     const std::vector<std::string> &exec_args,
                     bool is_external_generator);

      /**
       * @brief Destructor closing the process and thread handles
       */
      ~ProcessWindows();

      /**
       * @brief   Converts status to exit code
       * @return  Exit code of child process
       */
      int getExitCode() const;

      /**
       * @brief   Kill child process
       * @return  Success or failure
       */
      bool kill() const;

      /**
       * @brief   Checks if process is still running
       *
       */
      bool isRunning();

      /**
       * @brief   Launches the process
       * @return  Return code of CreateProcess()
       */
      int run();

      /**
       * @brief   Kill process if currently running
       */
      void killIfRunning();

};		// end of class ProcessWindows
#endif // PROCESSWINDOWS_HPP

#endif // _WIN32
