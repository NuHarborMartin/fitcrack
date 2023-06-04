/*
 * Author : see AUTHORS
 * Licence: MIT, see LICENSE
 */

#ifndef TASKNORMAL_HPP
#define TASKNORMAL_HPP

#include "TaskComputeBase.hpp"
#include "json.hpp"

/** Class representing cracking task */
class TaskNormal : public TaskComputeBase {

private:
  std::string passwords_; /**< Found password/s */

  unsigned long long start_index_; /**< Index from which start computation */
  uint64_t invalid_rules_count;

protected:
  /**
   * @brief   Getter of the password/s
   * @return  Found password/s
   */
  std::string getPasswords();

  /**
   * @brief   Parses Hashcat's progress output line
   * @param   progress_line [in] Line of the hashcat's output
   */
  bool parseHashcatStatus(const std::string &progress_line);

  /**
   * @brief   Reads password/s from the file
   */
  void readPasswordsFromFile();

  /**
   * @brief   Saves value from parameter into computed_hashes_
   * @param   computed_hashes_index [in] Values parsed from Hashcat's
   *	    progress line
   */
  void saveParsedProgress(uint64_t currentProgress);

  /**
   * @brief   Sets total_hashes_ to the second value after PROGRESS
   * @param   progress_line [] Hashcat's progress line
   */
  void setTotalHashesFromProgress(uint64_t current, uint64_t max,
                                  uint64_t saltCount);

public:
  /**
   * @brief   Constructor
   * @param   directory [in] Working directory object
   * @param   task_config [in] Task configuration file object
   * @param   host_config [in] Host configuration file object
   * @param   output_file [in] Name of the hashcat output file
   * @param   workunit_name [in] Name of the BOINC project workunit
   */
  TaskNormal(Directory &directory, ConfigTask task_config,
             ConfigHost host_config, const std::string &output_file,
             const std::string &workunit_name);

  /**
   * @brief   Generates task result information
   * @return  Information as string
   */
  std::string generateOutputMessage();

  /**
   * @brief Do nothing. It's already 0 and will be initialized when progress
   * line is parsed
   */
  void initializeTotalHashes() {}

  /**
   * @brief   Parses hashcat output line
   * @param   output_line [in] Output line from the hashcat process
   */
  bool parseHashcatOutputLine(std::string &output_line);

  /**
   * @brief  Handles monitoring of prgress with nofitication
   */
  void progress();
};

#endif // TASKNORMAL_HPP
