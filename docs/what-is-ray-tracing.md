# What is Ray Tracing?

Before we go into ray tracing, let's understand how our eyes see things.

## Physics of vision

Light sources emit light in all directions. When light hits an object, some of it is absorbed by the object, and some of it is reflected. The reflected light then travels in all directions. Some of it reaches our eyes, and we see the object.

When we look at an object, light from the object enters our eyes. The light is then focused by the lens onto the retina, which is a layer of light-sensitive cells at the back of our eyes. The retina converts the light into electrical signals and sends them to the brain through the optic nerve. The brain then processes the signals and forms an image of the object in our mind.

Now, let's see how we can simulate this process using ray tracing.

## Ray tracing: a brief introduction

Ray tracing is a technique for rendering 3D scenes. It enables computers to produce photorealistic results, that ideally, hard to disintguish from reality. In raytracing, we simulate the physics of vision by tracing the path of light rays from the camera to the objects in the scene. The light rays are traced in reverse, starting from the camera and ending at the light sources. The color of each pixel in the image is determined by the light rays that reach the camera. So we assume that the camera is emitting the light rays instead of receiving them to make the modeling easier.

Let me explain with an example, Imagine this very simple scene, a point in space, a light source that emits a single ray of light, and a camera. Let's see how the ray tracing algorithm works for this scene.

Imagine the camera as your eye, and the light source as a tiny sun. The goal of raytracing is to determine what the camera "sees" in this scene.

Now, let's break it down step by step:

- First, we shoot a ray from the camera into the scene. This ray is called the "camera ray" or "primary ray." We're trying to find out if this ray intersects with any objects in the scene. In our case, there's just a point in space, so let's say the ray hits that point.

- Next, we need to determine how the light from the light source interacts with the point. To do this, we shoot another ray from the point towards the light source. This ray is called the "shadow ray."
If the shadow ray reaches the light source without any obstructions, it means the point is directly illuminated by the light. In our simple scene, there are no other objects, so the point is indeed illuminated.

- Now, we need to calculate the color and intensity of the light at the point. This depends on the properties of the light source, the distance between the point and the light source, and the angle at which the light hits the point. In our case, since we have a single ray from the light source, the color and intensity are determined by that ray.

- Finally, we trace the path of the light back to the camera. This is done by calculating the reflection or refraction of the light, depending on the properties of the point and the surrounding medium. In our simple scene, we can assume that the point reflects the light directly back to the camera.

- The color and intensity of the light reaching the camera determine the final color of the pixel in the rendered image. In our case, the pixel corresponding to the point in space will have the color and intensity of the light reflected from the point.

Here is a simplified psudo-code for the ray tracing algorithm:

```python
for pixel in image:
    ray = camera.shoot_ray(pixel)
    intersection = scene.intersect(ray)
    if intersection:
        shadow_ray = intersection.point.shoot_ray(light_source)
        if shadow_ray.reaches(light_source):
            color = shadow_ray.color
        else:
            color = background_color
    else:
        color = background_color

    image.set_pixel(pixel, color)
```

### Let's talk about color calculations

#### Color description

Color is modeled as a vector of three numbers: red, green, and blue. Each number represents the intensity of the corresponding color component. For example, the color (1, 0, 0) is pure red, (0, 1, 0) is pure green, and (0, 0, 1) is pure blue. The color (1, 1, 1) is white, and (0, 0, 0) is black.

When a light ray with color vector L, hits a point with color vector P, the color of the point is calculated as follows:

```python
color = L * P
```

So simply the "tint" of the color of the final pixel is just a product of diferent other colors.

#### Back to raytracing

So, the camera shoots a ray towards a point (for now, we are just trying to calculate the color of a point) and the ray hits the point. Now, we need to calculate the color of the point. How do we do that?

The color of the point depends on the color of the light source, the distance between the point and the light source, and the angle at which the light hits the point. Let's see how we can calculate the color of the point using these factors.

First, let's talk about the color of the light source. The color of the light source is determined by the material of the light source. For example, if the light source is a red light bulb, then the color of the light is red. If the light source is a white light bulb, then the color of the light is white. If the light source is a blue light bulb, then the color of the light is blue. And so on. There are more properties of the light source that affect the color of the light, but we'll talk about them later.

Next, let's talk about the distance between the point and the light source. The distance between the point and the light source affects the intensity of the light. The farther the point is from the light source, the less intense the light is. The closer the point is to the light source, the more intense the light is. The intensity of the light is inversely proportional to the square of the distance between the point and the light source. For example, if the distance between the point and the light source is 1 meter, then the intensity of the light is 1/1^2 = 1. If the distance between the point and the light source is 2 meters, then the intensity of the light is 1/2^2 = 1/4 = 0.25. If the distance between the point and the light source is 3 meters, then the intensity of the light is 1/3^2 = 1/9 = 0.1111111111111111. And so on.

Finally, let's talk about the angle at which the light hits the point. The angle at which the light hits the point affects the color of the point.
To illustrate this better, let's ditch the point example and imagine a plane. The orientation of the plane and the angle at which the light ray intersects the plane determines how the surface should be illuminated. For example, if the plane is facing the light source, then the surface should be illuminated. If the plane is facing away from the light source, then the surface should not be illuminated. If the plane is facing the light source at an angle, then the surface should be illuminated, but not as much as if the plane was facing the light source directly. And so on.

