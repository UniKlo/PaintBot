# Centerpiece

<img src="https://imgur.com/B8fPiiH.jpg" width="200">

## Design Goals

- Hold the spray-gun in place as it shoots paint
- Displaced across 2D plane, attached to chain ends

[OnShape Document](https://cad.onshape.com/documents/9436b4b003238d1dfd9249e6/w/013a2f8b46f01adf8d57174f/e/b9008f226251bdd07a1122cc)

## Iterations

1. **Triangular Linkage** → [Maslow Implementation](http://maslowcommunitygarden.org/Maslow-triangulation-linkage-kit.html)

<img src="https://imgur.com/qjkO0tJ.jpg" width="300">

The figure above depicts a center-piece with two individual, three-bar connections. The chains connect to the solid blue dots in the middle of the second bar. The fixed points are at the four white holes with a blue cross. The advantages of this design as enumerated in in Maslow's kit:

- Improved accuracy
- Extremely simplified computation
- Much easier calibration
- Sled orientation/rotation becomes a non-issue

We extended this design to include two additional three-bar connections to stabilize the center-piece with a total of four chains. A plus of this design has the plus of having all the chains share the same origin on the center-piece (which is what ultimately makes the calculations simpler). The main drawback of this design is that, because the four-chains are free to move along an arc around the center-piece (the dotted red line above), any weight that shifts the center of gravity away from the origin of the chains will til the whole center-piece. For that reason, this design was scrapped. *poop emoji*

2. **Ring** → [Maslow Implementation](http://maslowcommunitygarden.org/Maslow-Ring-System.html)

Since the chains meet at the origin of the center-piece, this design has many of the same benefits as the system above only with quadrilateral kinematics as opposed to triangular. However, this design did not remain stable after spray-gun recoiled. 

<img src="https://imgur.com/QloOmfw.jpg" width="300">

Ring design with bricks to stabilize center-piece

<img src="https://imgur.com/eRbLdn3.jpg" width="300">

Maslow ring system 

### Future Ideas

Here are other linkage systems which could serve as a basis for other iterations of the center-piece:

<img src="https://imgur.com/2jxo4EO.jpg" width="600">

- [Tool for visualizing/testing kinematics](https://www.geogebra.org/)
