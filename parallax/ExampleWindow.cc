#include "ExampleWindow.h"
#include <stdexcept>
#include <SDL2/SDL_image.h>

ExampleWindow::ExampleWindow(int width, int height) :
		Window(width, height),
		_width_cloud(width / 4), _cloud_x(width), _cloud_x2(width + _width_cloud), _cloud_x3(width + _width_cloud *2), _cloud_x4(width + _width_cloud *3), _cloud_x5(width + _width_cloud * 4), _cloud_x6(width + _width_cloud * 5), _cloud_y(height / 90), _st_cloud(3),
		_width_sun(width/2.5), _sun_x(width), _sun_y(-height/15), _st_sun(2),
		_sky_x(0), _sky_x2(width), _sky_y(0),
		_mountes_y(height / 6),
		_st_slow(1), _st_fast(4),
		_st_lamppost(2), _lamppost_x(width/15), _lamppost_x2(width*12/15), _lamppost_y(height/2.6), _lamppost1_x(width/8), _lamppost1_x2(width/8*7), _lamppost1_y(height/2.1),
		_road_x(1), _road_x2(width), _road_y(height/5*3),
		_car_x(0), _car_y(height/1.5),
		_car1_x(0), _car1_y(height/1.8){

	//небо
	_sky = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "sky.jpg"), SDL_DestroyTexture);
	if (_sky == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить небо: ")
				+ std::string(SDL_GetError()));
	//горы
	_mountes = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "mountes.png"), SDL_DestroyTexture);
	if (_mountes == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить горы: ")
				+ std::string(SDL_GetError()));
	//облако1
	_cloud = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "cloud.png"), SDL_DestroyTexture);
	//облако2
	_cloud1 = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "cloud1.png"), SDL_DestroyTexture);
	if (_cloud == nullptr || _cloud1 == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить облака: ")
				+ std::string(SDL_GetError()));
	//солнце
	_sun = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "sun.png"), SDL_DestroyTexture);
	if (_sun == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить солнце: ")
				+ std::string(SDL_GetError()));
	//дорога
	_road = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "road.png"), SDL_DestroyTexture);
	if (_road == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить дорогу: ")
				+ std::string(SDL_GetError()));
	//машина1
	_car = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "car.png"), SDL_DestroyTexture);
	if (_car == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить машину1: ")
				+ std::string(SDL_GetError()));
	//столб1
	_lamppost = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "lamppost.png"), SDL_DestroyTexture);
	//столб2
	_lamppost1 = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "lamppost.png"), SDL_DestroyTexture);
	if (_lamppost == nullptr || _lamppost1 == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить столбы: ")
				+ std::string(SDL_GetError()));
	//машина2
	_car1 = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "car1.png"), SDL_DestroyTexture);
	if (_car1 == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить машину2: ")
				+ std::string(SDL_GetError()));
}

void ExampleWindow::render() {
	SDL_SetRenderDrawColor(_renderer.get(), 32, 32, 96, 255);
	SDL_RenderClear(_renderer.get());

	SDL_Rect sky_rect { _sky_x, _sky_y, width(), (height() / 2 + height() / 10) };
	SDL_Rect sky_rect2 { _sky_x2, _sky_y, width(), (height() / 2 + height() / 10) };
	SDL_Rect mountes_rect { _sky_x, _mountes_y, width(), height() / 2 };
	SDL_Rect mountes_rect2 { _sky_x2, _mountes_y, width(), height() / 2 };
	SDL_Rect lamppost_rect{ _lamppost_x, _lamppost_y, width()/5, height()/4};
	SDL_Rect lamppost_rect2{ _lamppost_x2, _lamppost_y, width()/5, height()/4};
	SDL_Rect car1_rect{ _car1_x, _car1_y, width()/5, height()/6};
	SDL_Rect lamppost1_rect{ _lamppost1_x, _lamppost1_y, width()/2, height()/2};
	SDL_Rect lamppost1_rect2{ _lamppost1_x2, _lamppost1_y, width()/2, height()/2};
	SDL_Rect cloud_rect { _cloud_x, _cloud_y + 100, _width_cloud, height() / 7 };
	SDL_Rect cloud_rect2 { _cloud_x2, _cloud_y + 180, _width_cloud, height() / 7 };
	SDL_Rect cloud_rect3 { _cloud_x3, _cloud_y + 50, _width_cloud, height() / 7 };
	SDL_Rect cloud_rect4 { _cloud_x4, _cloud_y + 180, _width_cloud, height() / 7 };
	SDL_Rect cloud_rect5 { _cloud_x5, _cloud_y + 50, _width_cloud, height() / 7 };
	SDL_Rect cloud_rect6 { _cloud_x6, _cloud_y + 180, _width_cloud, height() / 7 };
	SDL_Rect sun_rect{ _sun_x, _sun_y, _width_sun, _width_sun};
	SDL_Rect road_rect{ _road_x, _road_y, width(), height()/2};
	SDL_Rect road_rect2{ _road_x2, _road_y, width(), height()/2};
	SDL_Rect car_rect{ _car_x, _car_y, width()/5, height()/6};

	SDL_RenderCopy(_renderer.get(), _sky.get(), nullptr, &sky_rect);
	SDL_RenderCopyEx(_renderer.get(), _sky.get(), nullptr, &sky_rect2, 0, nullptr, SDL_FLIP_HORIZONTAL);
	SDL_RenderCopy(_renderer.get(), _cloud1.get(), nullptr, &cloud_rect2);
	SDL_RenderCopy(_renderer.get(), _cloud1.get(), nullptr, &cloud_rect4);
	SDL_RenderCopy(_renderer.get(), _cloud1.get(), nullptr, &cloud_rect6);
	SDL_RenderCopy(_renderer.get(), _sun.get(), nullptr, &sun_rect);
	SDL_RenderCopy(_renderer.get(), _mountes.get(), nullptr, &mountes_rect);
	SDL_RenderCopyEx(_renderer.get(), _mountes.get(), nullptr, &mountes_rect2, 0, nullptr, SDL_FLIP_HORIZONTAL);
	SDL_RenderCopy(_renderer.get(), _cloud.get(), nullptr, &cloud_rect);
	SDL_RenderCopy(_renderer.get(), _cloud.get(), nullptr, &cloud_rect5);
	SDL_RenderCopy(_renderer.get(), _cloud.get(), nullptr, &cloud_rect3);
	SDL_RenderCopy(_renderer.get(), _road.get(), nullptr, &road_rect);
	SDL_RenderCopyEx(_renderer.get(), _road.get(), nullptr, &road_rect2, 0, nullptr, SDL_FLIP_HORIZONTAL);
	SDL_RenderCopy(_renderer.get(), _lamppost.get(), nullptr, &lamppost_rect);
	SDL_RenderCopy(_renderer.get(), _lamppost.get(), nullptr, &lamppost_rect2);
	SDL_RenderCopy(_renderer.get(), _car.get(), nullptr, &car_rect);
	SDL_RenderCopy(_renderer.get(), _car1.get(), nullptr, &car1_rect);
	SDL_RenderCopy(_renderer.get(), _lamppost1.get(), nullptr, &lamppost1_rect);
	SDL_RenderCopy(_renderer.get(), _lamppost1.get(), nullptr, &lamppost1_rect2);

}

void ExampleWindow::do_logic() {
	_sky_x -= _st_slow;
	_sky_x2 -= _st_slow;
	_cloud_x -= _st_cloud;
	_cloud_x2 -= _st_cloud;
	_cloud_x3 -= _st_cloud;
	_cloud_x4 -= _st_cloud;
	_cloud_x5 -= _st_cloud;
	_cloud_x6 -= _st_cloud;
	_sun_x -= _st_sun;
	_road_x -= _st_slow;
	_road_x2 -= _st_slow;
	_car_x += _st_fast;
	_lamppost_x -= _st_lamppost;
	_lamppost_x2 -= _st_lamppost;
	_car1_x += _st_fast;
	_lamppost1_x -= _st_fast;
	_lamppost1_x2 -= _st_fast;

	if (_sky_x <= 0 - width()) {
		_sky_x = width();
	}
	if (_sky_x2 <= 0 - width()) {
		_sky_x2 = width();
	}
	if (_car_x > width()) {
		_car_x = -width();
	}
	if (_lamppost_x <= 0 - width()/4) {
		_lamppost_x = width();
	}
	if (_lamppost_x2 <= 0 - width()/4) {
		_lamppost_x2 = width();
	}

	_car1_x -= 10;
	if (_car1_x <= -1500) _car1_x = 1300;

	if (_lamppost1_x <= 0 - width()/2) {
		_lamppost1_x = width();
	}
	if (_lamppost1_x2 <= 0 - width()/2) {
		_lamppost1_x2 = width();
	}
	if (_cloud_x <= -_width_cloud) {
		_cloud_x = width();
	}
	if (_cloud_x2 <= -_width_cloud) {
		_cloud_x2 = width();
	}
	if (_cloud_x3 <= -_width_cloud) {
		_cloud_x3 = width();
	}
	if (_cloud_x4 <= -_width_cloud) {
		_cloud_x4 = width();
	}
	if (_cloud_x5 <= -_width_cloud) {
		_cloud_x5 = width();
	}
	if (_cloud_x6 <= -_width_cloud) {
		_cloud_x6 = width();
	}
	if (_sun_x <= 0-_width_sun) {
		_sun_x = width();
	}
	if (_sky_x <= 0 - width()) {
		_sky_x = width();
	}
	if (_sky_x2 <= 0 - width()) {
		_sky_x2 = width();
	}
	if (_road_x <= 0 - width()) {
		_road_x = width();
	}
	if (_road_x2 <= 0 - width()) {
		_road_x2 = width();
	}
}

void ExampleWindow::handle_keys(const Uint8 *keys) {
	if (keys[SDL_SCANCODE_LEFT] && _car_x >= 0){
		_car_x -= 3;
		}
	if (keys[SDL_SCANCODE_RIGHT] && _car_x <= 1040){
			_car_x += 3;
		}
	if (keys[SDL_SCANCODE_DOWN] && _car_y <= 650){
			_car_y += 3;
		}
	if (keys[SDL_SCANCODE_UP] && _car_y >= 520){
			_car_y -= 3;
		}
}
