#pragma once

namespace android {
  struct android_option
  {

  };

  class Android {
  public:
    explicit Android(android_option option);
    ~Android() = default;
  };

}
