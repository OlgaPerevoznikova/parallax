#ifndef EXAMPLEWINDOW_H_
#define EXAMPLEWINDOW_H_
#include "Window.h"

class ExampleWindow: public Window
{
protected:
	std::shared_ptr<SDL_Texture> _sky, _car1, _mountes, _cloud, _cloud1, _sun, _road, _car, _lamppost, _lamppost1;
	int _width_cloud, _width_sun, _sky_x, _sky_x2, _sun_x, _sun_y, _cloud_x, _cloud_x2, _cloud_x3, _cloud_x4, _cloud_x5, _cloud_x6, _sky_y, _mountes_y, _cloud_y, _st_slow, _st_cloud, _st_sun, _st_fast, _st_lamppost, _road_x, _road_x2, _road_y, _car_x, _car_y, _lamppost_x, _lamppost_x2, _lamppost_y, _car1_x, _car1_y, _lamppost1_x, _lamppost1_x2, _lamppost1_y;

public:
	ExampleWindow(
			int width = DEFAULT_WIDTH,
			int height = DEFAULT_HEIGHT);
	virtual ~ExampleWindow() = default;
	virtual void render() override;
	virtual void do_logic() override;
	virtual void handle_keys(const Uint8 *keys) override;
};

#endif /* EXAMPLEWINDOW_H_ */
