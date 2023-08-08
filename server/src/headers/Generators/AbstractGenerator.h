/**
 * @file AbstractGenerator.h
 * @brief Header file for AbstractGenerator, base class for generators
 * @authors Lukas Zobal (zobal.lukas(at)gmail.com)
 * @date 12. 12. 2018
 * @license MIT, see LICENSE
 */

#ifndef WORKGENERATOR_ABSTRACTGENERATOR_H
#define WORKGENERATOR_ABSTRACTGENERATOR_H

#include <Config.h>

#include <Host.h>
#include <Workunit.h>
#include <Mask.h>
#include <Job.h>


class CAbstractGenerator
{
    protected:
        /** Default constructor */
        CAbstractGenerator() = default;

        /**
         * @brief Infinite loop of generator
         */
        virtual void run() = 0;

        /**
         * Get desired duration of workunit
         * @return Number of seconds for a workunit
         */
        uint64_t getSecondsPerWorkunit(PtrJob &job, CSqlLoader &loader);

        /**
         * @brief Wait for the transitioner to create instances of the workunits we just created.
         * Otherwise we'll create too many workunits.
         */
        void activateJobs();

        /**
         * @brief Get list of job sticky files
         * @param job CJob which is done
         */
        std::vector<std::string> getStickyFiles(PtrJob &job);

        /**
         * @brief Send all job host a message to delete job sticky files
         * @param job CJob which is done
         */
        void deleteStickyFiles(PtrJob &job, std::vector<PtrHost> &jobHosts);
};

#endif //WORKGENERATOR_ABSTRACTGENERATOR_H
