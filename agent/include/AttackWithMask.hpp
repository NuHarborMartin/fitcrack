/*
 * Author : see AUTHORS
 * Licence: MIT, see LICENSE
 */

#ifndef ATTACKWITHMASK_HPP
#define ATTACKWITHMASK_HPP

#include "AttackCrackingBase.hpp"

#include "File.hpp"

/** Class representing hashcat's mask attack */
class AttackWithMask: public AttackCrackingBase {

protected:

	/**
	 * @brief   Adds mask to the file which is then passed to hashcat
	 * @param   mask_file [in] File to write to as a stream
	 */
	void addMask(const std::vector<std::string> &customCharsets);

	/**
	 * @brief   Creates mask file which is than passed to hashcat. It allows
	 *	    us to use '/' (slash) in mask without hashcat thinking it is
	 *	    a path to some file as proposed at
	 *	    https://hashcat.net/forum/thread-7738-post-41579.html#pid41579
	 *	    The file also contains charsets when some are specified
	 */
	void createMaskAndCharsets();

	/**
	 * @brief   Takes charset from ConfigTask and saves it to the file with
	 *	    \<charset_name\>.hcchr
	 * @param   charset_name [in] Charset name (charsetX)
	 * @param   content [in] Value of the charset saved in config
	*/
	std::string saveCharset(const std::string& charset_name, const std::string& content);


public:

	/**
	 * @brief   Basic constructor
	 * @param   config [in] Representation of config file
	 * @param   directory [in] Working directory
	 */
	AttackWithMask(const ConfigTask& config, Directory& directory);
};
#endif // ATTACKWITHMASK_HPP
