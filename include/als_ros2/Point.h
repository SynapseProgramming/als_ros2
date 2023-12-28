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

#ifndef __POINT_H__
#define __POINT_H__

namespace als_ros2
{

    /**
     * @brief Represents a point in a 2D coordinate system.
     */
    class Point
    {
    private:
        double x_, y_;

    public:
        /**
         * @brief Default constructor. Initializes the point with coordinates (0, 0).
         */
        Point() : x_(0.0), y_(0.0){};

        /**
         * @brief Constructor that initializes the point with the given coordinates.
         * @param x The x-coordinate of the point.
         * @param y The y-coordinate of the point.
         */
        Point(double x, double y) : x_(x), y_(y){};

        /**
         * @brief Destructor.
         */
        ~Point(){};

        /**
         * @brief Sets the x-coordinate of the point.
         * @param x The new x-coordinate.
         */
        inline void setX(double x) { x_ = x; }

        /**
         * @brief Sets the y-coordinate of the point.
         * @param y The new y-coordinate.
         */
        inline void setY(double y) { y_ = y; }

        /**
         * @brief Sets the coordinates of the point.
         * @param x The new x-coordinate.
         * @param y The new y-coordinate.
         */
        inline void setPoint(double x, double y) { x_ = x, y_ = y; }

        /**
         * @brief Sets the coordinates of the point to match another point.
         * @param p The point to copy the coordinates from.
         */
        inline void setPoint(Point p) { x_ = p.x_, y_ = p.y_; }

        /**
         * @brief Gets the x-coordinate of the point.
         * @return The x-coordinate.
         */
        inline double getX(void) { return x_; }

        /**
         * @brief Gets the y-coordinate of the point.
         * @return The y-coordinate.
         */
        inline double getY(void) { return y_; }

        /**
         * @brief Gets a copy of the point.
         * @return A new point with the same coordinates.
         */
        inline Point getPoint(void) { return Point(x_, y_); }

    }; // class Point

} // namespace als_ros2

#endif // __POINT_H__
