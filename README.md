# Hyperion

Hyperion is a lightweight 3D engine written in C++, capable of rendering 3D geometry directly to the terminal using ASCII characters. This project was developed to explore the fundamentals of computer graphics, 3D mathematical transformations, and software rendering without relying on external graphics libraries.

<div align="center">
  <img src="https://github.com/user-attachments/assets/004ac6ec-90eb-451b-90e9-43c7083a3be3" width="614" alt="Hyperion Demo">
</div>

## Current Version

v0.2.0

## Key Features

* **Native 3D Pipeline:** Built from scratch. All mathematical transformations and projections are implemented manually, using zero external math or graphics libraries.
* **Quaternion-based Rotation:** Utilized quaternions to handle 3D rotations, effectively eliminating the risk of gimbal lock and ensuring smooth orientation transitions.
* **Framerate Independence:** Integrated `Delta Time` logic, ensuring consistent animation speed regardless of the host hardware's performance.
* **Back-face Culling:** Face orientation testing using surface normals and view vectors to eliminate non-visible geometry, improving rendering clarity and performance.
* **Triangle-based Mesh Representation:** Transitioned from edge-only geometry to a full face/triangle mesh system, enabling more accurate and scalable 3D object representation.

## 🗺️ Planned Features
- **Line clipping**
- **Filled triangle rendering**
- **Lighting (Lambert shading)**
- **Depth buffer (z-buffer)**
- **Scene system**

## Coming soon
* **⚙️ How It Works**
* **💻 Usage**
