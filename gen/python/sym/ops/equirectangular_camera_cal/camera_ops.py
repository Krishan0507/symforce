# -----------------------------------------------------------------------------
# This file was autogenerated by symforce from template:
#     cam_package/ops/CLASS/camera_ops.py.jinja
# Do NOT modify by hand.
# -----------------------------------------------------------------------------

import math
import typing as T

import numpy

import sym  # pylint: disable=unused-import


class CameraOps(object):
    """
    Python CameraOps implementation for :py:class:`symforce.cam.equirectangular_camera_cal.EquirectangularCameraCal`.
    """

    @staticmethod
    def focal_length(self):
        # type: (sym.EquirectangularCameraCal) -> numpy.ndarray
        """
        Return the focal length.
        """

        # Total ops: 0

        # Input arrays
        _self = self.data

        # Intermediate terms (0)

        # Output terms
        _focal_length = numpy.zeros(2)
        _focal_length[0] = _self[0]
        _focal_length[1] = _self[1]
        return _focal_length

    @staticmethod
    def principal_point(self):
        # type: (sym.EquirectangularCameraCal) -> numpy.ndarray
        """
        Return the principal point.
        """

        # Total ops: 0

        # Input arrays
        _self = self.data

        # Intermediate terms (0)

        # Output terms
        _principal_point = numpy.zeros(2)
        _principal_point[0] = _self[2]
        _principal_point[1] = _self[3]
        return _principal_point

    @staticmethod
    def pixel_from_camera_point(self, point, epsilon):
        # type: (sym.EquirectangularCameraCal, numpy.ndarray, float) -> T.Tuple[numpy.ndarray, float]
        """
        Project a 3D point in the camera frame into 2D pixel coordinates.

        Returns:
            pixel: (x, y) coordinate in pixels if valid
            is_valid: 1 if the operation is within bounds else 0
        """

        # Total ops: 19

        # Input arrays
        _self = self.data
        if point.shape == (3,):
            point = point.reshape((3, 1))
        elif point.shape != (3, 1):
            raise IndexError(
                "point is expected to have shape (3, 1) or (3,); instead had shape {}".format(
                    point.shape
                )
            )

        # Intermediate terms (1)
        _tmp0 = point[0, 0] ** 2 + point[2, 0] ** 2

        # Output terms
        _pixel = numpy.zeros(2)
        _pixel[0] = (
            _self[0]
            * math.atan2(
                point[0, 0],
                epsilon * ((0.0 if point[2, 0] == 0 else math.copysign(1, point[2, 0])) + 0.5)
                + point[2, 0],
            )
            + _self[2]
        )
        _pixel[1] = _self[1] * math.atan2(point[1, 0], math.sqrt(_tmp0 + epsilon)) + _self[3]
        _is_valid = max(
            0,
            (0.0 if _tmp0 + point[1, 0] ** 2 == 0 else math.copysign(1, _tmp0 + point[1, 0] ** 2)),
        )
        return _pixel, _is_valid

    @staticmethod
    def pixel_from_camera_point_with_jacobians(self, point, epsilon):
        # type: (sym.EquirectangularCameraCal, numpy.ndarray, float) -> T.Tuple[numpy.ndarray, float, numpy.ndarray, numpy.ndarray]
        """
        Project a 3D point in the camera frame into 2D pixel coordinates.

        Returns:
            pixel: (x, y) coordinate in pixels if valid
            is_valid: 1 if the operation is within bounds else 0
            pixel_D_cal: Derivative of pixel with respect to intrinsic calibration parameters
            pixel_D_point: Derivative of pixel with respect to point
        """

        # Total ops: 34

        # Input arrays
        _self = self.data
        if point.shape == (3,):
            point = point.reshape((3, 1))
        elif point.shape != (3, 1):
            raise IndexError(
                "point is expected to have shape (3, 1) or (3,); instead had shape {}".format(
                    point.shape
                )
            )

        # Intermediate terms (10)
        _tmp0 = (
            epsilon * ((0.0 if point[2, 0] == 0 else math.copysign(1, point[2, 0])) + 0.5)
            + point[2, 0]
        )
        _tmp1 = math.atan2(point[0, 0], _tmp0)
        _tmp2 = point[0, 0] ** 2
        _tmp3 = _tmp2 + point[2, 0] ** 2
        _tmp4 = math.sqrt(_tmp3 + epsilon)
        _tmp5 = math.atan2(point[1, 0], _tmp4)
        _tmp6 = _tmp3 + point[1, 0] ** 2
        _tmp7 = _self[0] / (_tmp0 ** 2 + _tmp2)
        _tmp8 = _self[1] / (_tmp6 + epsilon)
        _tmp9 = _tmp8 * point[1, 0] / _tmp4

        # Output terms
        _pixel = numpy.zeros(2)
        _pixel[0] = _self[0] * _tmp1 + _self[2]
        _pixel[1] = _self[1] * _tmp5 + _self[3]
        _is_valid = max(0, (0.0 if _tmp6 == 0 else math.copysign(1, _tmp6)))
        _pixel_D_cal = numpy.zeros((2, 4))
        _pixel_D_cal[0, 0] = _tmp1
        _pixel_D_cal[1, 0] = 0
        _pixel_D_cal[0, 1] = 0
        _pixel_D_cal[1, 1] = _tmp5
        _pixel_D_cal[0, 2] = 1
        _pixel_D_cal[1, 2] = 0
        _pixel_D_cal[0, 3] = 0
        _pixel_D_cal[1, 3] = 1
        _pixel_D_point = numpy.zeros((2, 3))
        _pixel_D_point[0, 0] = _tmp0 * _tmp7
        _pixel_D_point[1, 0] = -_tmp9 * point[0, 0]
        _pixel_D_point[0, 1] = 0
        _pixel_D_point[1, 1] = _tmp4 * _tmp8
        _pixel_D_point[0, 2] = -_tmp7 * point[0, 0]
        _pixel_D_point[1, 2] = -_tmp9 * point[2, 0]
        return _pixel, _is_valid, _pixel_D_cal, _pixel_D_point

    @staticmethod
    def camera_ray_from_pixel(self, pixel, epsilon):
        # type: (sym.EquirectangularCameraCal, numpy.ndarray, float) -> T.Tuple[numpy.ndarray, float]
        """
        Backproject a 2D pixel coordinate into a 3D ray in the camera frame.

        Returns:
            camera_ray: The ray in the camera frame (NOT normalized)
            is_valid: 1 if the operation is within bounds else 0
        """

        # Total ops: 19

        # Input arrays
        _self = self.data
        if pixel.shape == (2,):
            pixel = pixel.reshape((2, 1))
        elif pixel.shape != (2, 1):
            raise IndexError(
                "pixel is expected to have shape (2, 1) or (2,); instead had shape {}".format(
                    pixel.shape
                )
            )

        # Intermediate terms (3)
        _tmp0 = (-_self[3] + pixel[1, 0]) / _self[1]
        _tmp1 = math.cos(_tmp0)
        _tmp2 = (-_self[2] + pixel[0, 0]) / _self[0]

        # Output terms
        _camera_ray = numpy.zeros(3)
        _camera_ray[0] = _tmp1 * math.sin(_tmp2)
        _camera_ray[1] = math.sin(_tmp0)
        _camera_ray[2] = _tmp1 * math.cos(_tmp2)
        _is_valid = max(
            0,
            min(
                (0.0 if math.pi - abs(_tmp2) == 0 else math.copysign(1, math.pi - abs(_tmp2))),
                (
                    0.0
                    if -abs(_tmp0) + (1.0 / 2.0) * math.pi == 0
                    else math.copysign(1, -abs(_tmp0) + (1.0 / 2.0) * math.pi)
                ),
            ),
        )
        return _camera_ray, _is_valid

    @staticmethod
    def camera_ray_from_pixel_with_jacobians(self, pixel, epsilon):
        # type: (sym.EquirectangularCameraCal, numpy.ndarray, float) -> T.Tuple[numpy.ndarray, float, numpy.ndarray, numpy.ndarray]
        """
        Backproject a 2D pixel coordinate into a 3D ray in the camera frame.

        Returns:
            camera_ray: The ray in the camera frame (NOT normalized)
            is_valid: 1 if the operation is within bounds else 0
            point_D_cal: Derivative of point with respect to intrinsic calibration parameters
            point_D_pixel: Derivation of point with respect to pixel
        """

        # Total ops: 44

        # Input arrays
        _self = self.data
        if pixel.shape == (2,):
            pixel = pixel.reshape((2, 1))
        elif pixel.shape != (2, 1):
            raise IndexError(
                "pixel is expected to have shape (2, 1) or (2,); instead had shape {}".format(
                    pixel.shape
                )
            )

        # Intermediate terms (21)
        _tmp0 = -_self[3] + pixel[1, 0]
        _tmp1 = 1 / _self[1]
        _tmp2 = _tmp0 * _tmp1
        _tmp3 = math.cos(_tmp2)
        _tmp4 = -_self[2] + pixel[0, 0]
        _tmp5 = 1 / _self[0]
        _tmp6 = _tmp4 * _tmp5
        _tmp7 = math.sin(_tmp6)
        _tmp8 = _tmp3 * _tmp7
        _tmp9 = math.sin(_tmp2)
        _tmp10 = math.cos(_tmp6)
        _tmp11 = _tmp10 * _tmp3
        _tmp12 = _tmp4 / _self[0] ** 2
        _tmp13 = _tmp0 / _self[1] ** 2
        _tmp14 = _tmp13 * _tmp9
        _tmp15 = _tmp11 * _tmp5
        _tmp16 = _tmp5 * _tmp8
        _tmp17 = _tmp1 * _tmp9
        _tmp18 = _tmp17 * _tmp7
        _tmp19 = _tmp1 * _tmp3
        _tmp20 = _tmp10 * _tmp17

        # Output terms
        _camera_ray = numpy.zeros(3)
        _camera_ray[0] = _tmp8
        _camera_ray[1] = _tmp9
        _camera_ray[2] = _tmp11
        _is_valid = max(
            0,
            min(
                (0.0 if math.pi - abs(_tmp6) == 0 else math.copysign(1, math.pi - abs(_tmp6))),
                (
                    0.0
                    if -abs(_tmp2) + (1.0 / 2.0) * math.pi == 0
                    else math.copysign(1, -abs(_tmp2) + (1.0 / 2.0) * math.pi)
                ),
            ),
        )
        _point_D_cal = numpy.zeros((3, 4))
        _point_D_cal[0, 0] = -_tmp11 * _tmp12
        _point_D_cal[1, 0] = 0
        _point_D_cal[2, 0] = _tmp12 * _tmp8
        _point_D_cal[0, 1] = _tmp14 * _tmp7
        _point_D_cal[1, 1] = -_tmp13 * _tmp3
        _point_D_cal[2, 1] = _tmp10 * _tmp14
        _point_D_cal[0, 2] = -_tmp15
        _point_D_cal[1, 2] = 0
        _point_D_cal[2, 2] = _tmp16
        _point_D_cal[0, 3] = _tmp18
        _point_D_cal[1, 3] = -_tmp19
        _point_D_cal[2, 3] = _tmp20
        _point_D_pixel = numpy.zeros((3, 2))
        _point_D_pixel[0, 0] = _tmp15
        _point_D_pixel[1, 0] = 0
        _point_D_pixel[2, 0] = -_tmp16
        _point_D_pixel[0, 1] = -_tmp18
        _point_D_pixel[1, 1] = _tmp19
        _point_D_pixel[2, 1] = -_tmp20
        return _camera_ray, _is_valid, _point_D_cal, _point_D_pixel
