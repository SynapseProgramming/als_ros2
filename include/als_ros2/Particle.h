/****************************************************************************
 * als_ros: An Advanced Localization System for ROS use with 2D LiDAR
 * Copyright (C) 2022 Naoki Akai
 *
 * Licensed under the Apache License, Version 2.0 (the “License”);
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an “AS IS” BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @author Naoki Akai
 * modified by: Roald Ong
 ****************************************************************************/

#ifndef __PARTICLE_H__
#define __PARTICLE_H__

#include <als_ros2/Pose.h>

namespace als_ros2
{

    /**
     * @class Particle
     * @brief Represents a particle in a particle filter.
     *
     * The Particle class stores the pose and weight of a particle.
     * It provides methods to access and modify the pose and weight.
     */
    class Particle
    {
    private:
        Pose pose_; ///< The pose of the particle.
        double w_;  ///< The weight of the particle.

    public:
        /**
         * @brief Default constructor.
         *
         * Initializes the pose to (0, 0, 0) and the weight to 0.
         */
        Particle() : pose_(0.0, 0.0, 0.0), w_(0.0){};

        /**
         * @brief Constructor with pose and weight parameters.
         *
         * @param x The x-coordinate of the pose.
         * @param y The y-coordinate of the pose.
         * @param yaw The yaw angle of the pose.
         * @param w The weight of the particle.
         */
        Particle(double x, double y, double yaw, double w) : pose_(x, y, yaw), w_(w){};

        /**
         * @brief Constructor with pose and weight parameters.
         *
         * @param p The pose of the particle.
         * @param w The weight of the particle.
         */
        Particle(Pose p, double w) : pose_(p), w_(w){};

        /**
         * @brief Destructor.
         */
        ~Particle(){};

        /**
         * @brief Get the x-coordinate of the particle's pose.
         *
         * @return The x-coordinate.
         */
        inline double getX(void) { return pose_.getX(); }

        /**
         * @brief Get the y-coordinate of the particle's pose.
         *
         * @return The y-coordinate.
         */
        inline double getY(void) { return pose_.getY(); }

        /**
         * @brief Get the yaw angle of the particle's pose.
         *
         * @return The yaw angle.
         */
        inline double getYaw(void) { return pose_.getYaw(); }

        /**
         * @brief Get the pose of the particle.
         *
         * @return The pose.
         */
        inline Pose getPose(void) { return pose_; }

        /**
         * @brief Get the weight of the particle.
         *
         * @return The weight.
         */
        inline double getW(void) { return w_; }

        /**
         * @brief Set the x-coordinate of the particle's pose.
         *
         * @param x The new x-coordinate.
         */
        inline void setX(double x) { pose_.setX(x); }

        /**
         * @brief Set the y-coordinate of the particle's pose.
         *
         * @param y The new y-coordinate.
         */
        inline void setY(double y) { pose_.setY(y); }

        /**
         * @brief Set the yaw angle of the particle's pose.
         *
         * @param yaw The new yaw angle.
         */
        inline void setYaw(double yaw) { pose_.setYaw(yaw); }

        /**
         * @brief Set the pose of the particle.
         *
         * @param x The new x-coordinate of the pose.
         * @param y The new y-coordinate of the pose.
         * @param yaw The new yaw angle of the pose.
         */
        inline void setPose(double x, double y, double yaw) { pose_.setPose(x, y, yaw); }

        /**
         * @brief Set the pose of the particle.
         *
         * @param p The new pose.
         */
        inline void setPose(Pose p) { pose_.setPose(p); }

        /**
         * @brief Set the weight of the particle.
         *
         * @param w The new weight.
         */
        inline void setW(double w) { w_ = w; }
    }; // class Particle

} // namespace als_ros2

#endif // __PARTICLE_H__