/*
 * Author : see AUTHORS
 * Licence: MIT, see LICENSE
 */

#ifndef TASK_HPP 
#define TASK_HPP

#include "ConfigTask.hpp"

#include "Constants.hpp"

#include "TaskBase.hpp"
#include "TaskBenchmark.hpp"
#include "TaskBenchmarkAll.hpp"
#include "TaskNormal.hpp"

/** Namespace with function for creating new Task */
namespace Task {
    extern std::string HostConfigPath; /**< OS dependent path to the ConfigHost file */
    extern std::string OutputFileName; /**< Default name of output file */

    /**
     * @brief	Function creating specific type of TaskBase based on config
     * @param	config_file [in] Configuration file
     * @param	directory [in] Working directory
     * @return	Pointer to the created task 
     */
    TaskBase* create(File &config_file, Directory& directory);

    /**
     * @brief	Gets workunit name
     * @return	Workunit name 
     */
    std::string getWorkunitName(); 

    /**
     * @brief   Parses workunit name from the init_data XML
     * @return  Value of the workunit element 
     */
    std::string parseWorkunitName();

    /**
     * @brief   Sets HostConfigPath
     */
    void setHostConfigPath();
};

#endif // TASK_HPP
