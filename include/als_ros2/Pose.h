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

#ifndef __POSE_H__
#define __POSE_H__

#include <cmath>

namespace als_ros2
{

    /**
     * @brief Represents a pose in 2D space.
     */
    class Pose
    {
    private:
        double x_, y_, yaw_;

        /**
         * @brief Modifies the yaw angle to be within the range [-pi, pi].
         */
        void modifyYaw(void)
        {
            while (yaw_ < -M_PI)
                yaw_ += 2.0 * M_PI;
            while (yaw_ > M_PI)
                yaw_ -= 2.0 * M_PI;
        }

    public:
        /**
         * @brief Default constructor. Initializes the pose with zero values.
         */
        Pose() : x_(0.0), y_(0.0), yaw_(0.0){};

        /**
         * @brief Constructor that initializes the pose with the given values.
         * @param x The x-coordinate of the pose.
         * @param y The y-coordinate of the pose.
         * @param yaw The yaw angle of the pose.
         */
        Pose(double x, double y, double yaw) : x_(x), y_(y), yaw_(yaw){};

        /**
         * @brief Destructor.
         */
        ~Pose(){};

        /**
         * @brief Sets the x-coordinate of the pose.
         * @param x The new x-coordinate.
         */
        inline void setX(double x) { x_ = x; }

        /**
         * @brief Sets the y-coordinate of the pose.
         * @param y The new y-coordinate.
         */
        inline void setY(double y) { y_ = y; }

        /**
         * @brief Sets the yaw angle of the pose.
         * @param yaw The new yaw angle.
         */
        inline void setYaw(double yaw) { yaw_ = yaw, modifyYaw(); }

        /**
         * @brief Sets the pose with the given values.
         * @param x The new x-coordinate.
         * @param y The new y-coordinate.
         * @param yaw The new yaw angle.
         */
        inline void setPose(double x, double y, double yaw) { x_ = x, y_ = y, yaw_ = yaw, modifyYaw(); }

        /**
         * @brief Sets the pose with the values from another pose.
         * @param p The pose to copy the values from.
         */
        inline void setPose(Pose p) { x_ = p.x_, y_ = p.y_, yaw_ = p.yaw_, modifyYaw(); }

        /**
         * @brief Gets the x-coordinate of the pose.
         * @return The x-coordinate.
         */
        inline double getX(void) { return x_; }

        /**
         * @brief Gets the y-coordinate of the pose.
         * @return The y-coordinate.
         */
        inline double getY(void) { return y_; }

        /**
         * @brief Gets the yaw angle of the pose.
         * @return The yaw angle.
         */
        inline double getYaw(void) { return yaw_; }

        /**
         * @brief Gets a copy of the pose.
         * @return A new pose object with the same values.
         */
        inline Pose getPose(void) { return Pose(x_, y_, yaw_); }

    }; // class Pose

} // namespace als_ros2

#endif // __POSE_H__