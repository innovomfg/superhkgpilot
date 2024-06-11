#pragma once

#include <memory>
#include <utility>

#include "system/camerad/cameras/camera_common.h"
#include "system/camerad/cameras/camera_util.h"
#include "system/camerad/sensors/sensor.h"
#include "common/params.h"
#include "common/util.h"

#define FRAME_BUF_COUNT 4

<<<<<<< HEAD
struct CameraConfig {
  int camera_num;
  VisionStreamType stream_type;
  float focal_len;  // millimeters
  const char *publish_name;
  cereal::FrameData::Builder (cereal::Event::Builder::*init_camera_state)();
  bool enabled;
};

const CameraConfig WIDE_ROAD_CAMERA_CONFIG = {
  .camera_num = 0,
  .stream_type = VISION_STREAM_WIDE_ROAD,
  .focal_len = 1.71,
  .publish_name = "wideRoadCameraState",
  .init_camera_state = &cereal::Event::Builder::initWideRoadCameraState,
  .enabled = !getenv("DISABLE_WIDE_ROAD"),
};

const CameraConfig ROAD_CAMERA_CONFIG = {
  .camera_num = 1,
  .stream_type = VISION_STREAM_ROAD,
  .focal_len = 8.0,
  .publish_name = "roadCameraState",
  .init_camera_state = &cereal::Event::Builder::initRoadCameraState,
  .enabled = !getenv("DISABLE_ROAD"),
};

const CameraConfig DRIVER_CAMERA_CONFIG = {
  .camera_num = 2,
  .stream_type = VISION_STREAM_DRIVER,
  .focal_len = 1.71,
  .publish_name = "driverCameraState",
  .init_camera_state = &cereal::Event::Builder::initDriverCameraState,
  .enabled = !getenv("DISABLE_DRIVER"),
};

class CameraState {
public:
  MultiCameraState *multi_cam_state = nullptr;
  std::unique_ptr<const SensorInfo> ci;
  bool enabled = true;
  VisionStreamType stream_type;
  const char *publish_name = nullptr;
  cereal::FrameData::Builder (cereal::Event::Builder::*init_camera_state)() = nullptr;
  float focal_len = 0;

  std::mutex exp_lock;

  int exposure_time = 5;
  bool dc_gain_enabled = false;
  int dc_gain_weight = 0;
  int gain_idx = 0;
  float analog_gain_frac = 0;

  float cur_ev[3] = {};
  float best_ev_score = 0;
  int new_exp_g = 0;
  int new_exp_t = 0;

  Rect ae_xywh = {};
  float measured_grey_fraction = 0;
  float target_grey_fraction = 0.3;
=======
#define ROAD_FL_MM 8.0f
#define WIDE_FL_MM 1.71f
#define DRIVER_FL_MM 1.71f

class CameraState {
public:
  MultiCameraState *multi_cam_state;
  std::unique_ptr<const SensorInfo> ci;
  bool enabled;

  std::mutex exp_lock;

  int exposure_time;
  bool dc_gain_enabled;
  int dc_gain_weight;
  int gain_idx;
  float analog_gain_frac;

  float cur_ev[3];
  float best_ev_score;
  int new_exp_g;
  int new_exp_t;

  Rect ae_xywh;
  float measured_grey_fraction;
  float target_grey_fraction;
>>>>>>> 8b9791041 (sunnypilot v2024.06.11-2039)

  unique_fd sensor_fd;
  unique_fd csiphy_fd;

<<<<<<< HEAD
  int camera_num = 0;
  float fl_pix = 0;

  CameraState(MultiCameraState *multi_camera_state, const CameraConfig &config);
=======
  int camera_num;
  float fl_pix;

>>>>>>> 8b9791041 (sunnypilot v2024.06.11-2039)
  void handle_camera_event(void *evdat);
  void update_exposure_score(float desired_ev, int exp_t, int exp_g_idx, float exp_gain);
  void set_camera_exposure(float grey_frac);

  void sensors_start();

<<<<<<< HEAD
  void camera_open();
  void set_exposure_rect();
  void sensor_set_parameters();
  void camera_map_bufs();
  void camera_init(VisionIpcServer *v, cl_device_id device_id, cl_context ctx);
  void camera_close();
  void run();

  int32_t session_handle = -1;
  int32_t sensor_dev_handle = -1;
  int32_t isp_dev_handle = -1;
  int32_t csiphy_dev_handle = -1;

  int32_t link_handle = -1;

  int buf0_handle = 0;
  int buf_handle[FRAME_BUF_COUNT] = {};
  int sync_objs[FRAME_BUF_COUNT] = {};
  uint64_t request_ids[FRAME_BUF_COUNT] = {};
  uint64_t request_id_last = 0;
  uint64_t frame_id_last = 0;
  uint64_t idx_offset = 0;
  bool skipped = true;
=======
  void camera_open(MultiCameraState *multi_cam_state, int camera_num, bool enabled);
  void set_exposure_rect();
  void sensor_set_parameters();
  void camera_map_bufs(MultiCameraState *s);
  void camera_init(MultiCameraState *s, VisionIpcServer *v, cl_device_id device_id, cl_context ctx, VisionStreamType yuv_type, float focal_len);
  void camera_close();

  int32_t session_handle;
  int32_t sensor_dev_handle;
  int32_t isp_dev_handle;
  int32_t csiphy_dev_handle;

  int32_t link_handle;

  int buf0_handle;
  int buf_handle[FRAME_BUF_COUNT];
  int sync_objs[FRAME_BUF_COUNT];
  int request_ids[FRAME_BUF_COUNT];
  int request_id_last;
  int frame_id_last;
  int idx_offset;
  bool skipped;
>>>>>>> 8b9791041 (sunnypilot v2024.06.11-2039)

  CameraBuf buf;
  MemoryManager mm;

  void config_isp(int io_mem_handle, int fence, int request_id, int buf0_mem_handle, int buf0_offset);
<<<<<<< HEAD
  void enqueue_req_multi(uint64_t start, int n, bool dp);
=======
  void enqueue_req_multi(int start, int n, bool dp);
>>>>>>> 8b9791041 (sunnypilot v2024.06.11-2039)
  void enqueue_buffer(int i, bool dp);
  int clear_req_queue();

  int sensors_init();
  void sensors_poke(int request_id);
  void sensors_i2c(const struct i2c_random_wr_payload* dat, int len, int op_code, bool data_word);

private:
<<<<<<< HEAD
  bool openSensor();
  void configISP();
  void configCSIPHY();
  void linkDevices();

=======
>>>>>>> 8b9791041 (sunnypilot v2024.06.11-2039)
  // for debugging
  Params params;
};

<<<<<<< HEAD
class MultiCameraState {
public:
  MultiCameraState();

  unique_fd video0_fd;
  unique_fd cam_sync_fd;
  unique_fd isp_fd;
  int device_iommu = -1;
  int cdm_iommu = -1;
=======
typedef struct MultiCameraState {
  unique_fd video0_fd;
  unique_fd cam_sync_fd;
  unique_fd isp_fd;
  int device_iommu;
  int cdm_iommu;
>>>>>>> 8b9791041 (sunnypilot v2024.06.11-2039)

  CameraState road_cam;
  CameraState wide_road_cam;
  CameraState driver_cam;

  PubMaster *pm;
<<<<<<< HEAD
};
=======
} MultiCameraState;
>>>>>>> 8b9791041 (sunnypilot v2024.06.11-2039)
